#pragma once
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Verifier.h>
#include <memory>
#include <map>
#include <string>

class CodeGenContext {
public:
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;

    // Simple symbol table for locals in a function.
    std::map<std::string, llvm::AllocaInst*> namedValues;

    CodeGenContext() {
        context = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("glang_module", *context);
        builder = std::make_unique<llvm::IRBuilder<>>(*context);
    }

    llvm::Function* currentFunction = nullptr;

    void setupBuiltins();
};
