#include "ast.hh"
#include "codegen.hh"
#include <string>

#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/TargetParser/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#if LLVM_VERSION_MAJOR >= 17
#  include <llvm/TargetParser/Triple.h>
#else
#  include <llvm/ADT/Triple.h>
#endif
#include <llvm/MC/TargetRegistry.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>

extern int yyparse();
extern FILE* yyin;
std::unique_ptr<ProgramNode> programBlock;

int main(int argc, char** argv) {
    if (argc < 2) {
        llvm::errs() << "Usage: " << argv[0] << " <source_file> [--emit-llvm | -c]\n";
        return 1;
    }

    std::string filename = argv[1];
    bool emitLLVM = false;
    bool emitObject = false;

    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--emit-llvm") {
            emitLLVM = true;
        } else if (arg == "-c" || arg == "--object") {
            emitObject = true;
        }
    }

    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        llvm::errs() << "Could not open file: " << filename << "\n";
        return 1;
    }

    yyin = file;
    yyparse();
    fclose(file);

    if (!programBlock) {
        llvm::errs() << "Parsing failed.\n";
        return 1;
    }

    CodeGenContext ctx;
    ctx.setupBuiltins();
    programBlock->codegen(ctx);

    if (emitLLVM) {
        ctx.module->print(llvm::outs(), nullptr);
        return 0;
    }

    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    auto TargetTriple = llvm::Triple(llvm::sys::getDefaultTargetTriple());
    ctx.module->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

    if (!Target) {
        llvm::errs() << Error;
        return 1;
    }

    auto CPU = "generic";
    auto Features = "";
    llvm::TargetOptions opt;
    auto RM = std::optional<llvm::Reloc::Model>();
    auto TheTargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    ctx.module->setDataLayout(TheTargetMachine->createDataLayout());

    if (emitObject) {
        auto Filename = "output.o";
        std::error_code EC;
        llvm::raw_fd_ostream dest(Filename, EC, llvm::sys::fs::OF_None);

        if (EC) {
            llvm::errs() << "Could not open file: " << EC.message() << "\n";
            return 1;
        }

        llvm::legacy::PassManager pass;
#if LLVM_VERSION_MAJOR >= 18
        auto FileType = llvm::CodeGenFileType::ObjectFile;
#else
        auto FileType = llvm::CGFT_ObjectFile;
#endif

        if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
            llvm::errs() << "TheTargetMachine can't emit a file of this type\n";
            return 1;
        }

        pass.run(*ctx.module);
        dest.flush();
        llvm::outs() << "Object file written to " << Filename << "\n";
        return 0;
    }

    // JIT Execution
    llvm::EngineBuilder builder(std::move(ctx.module));
    builder.setEngineKind(llvm::EngineKind::JIT);
    llvm::ExecutionEngine* ee = builder.create();

    if (!ee) {
        llvm::errs() << "Failed to create ExecutionEngine\n";
        return 1;
    }

    llvm::Function* mainFunc = ee->FindFunctionNamed("main");
    if (!mainFunc) {
        llvm::errs() << "No main function found to execute.\n";
        return 1;
    }

    ee->finalizeObject();
    std::vector<llvm::GenericValue> noargs;
    llvm::GenericValue v = ee->runFunction(mainFunc, noargs);
    auto returnValue = v.IntVal.getSExtValue();
    llvm::outs() << "Program exited with code: " << returnValue << "\n";

    return 0;
}
