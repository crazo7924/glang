#include "codegen.hpp"
#include "ast.hpp"
#include "parser.hpp" // For token definitions (T_PLUS etc.)
#include <iostream>

using namespace llvm;

void CodeGenContext::setupBuiltins() {
    // printf
    std::vector<Type*> printfArgs;
    printfArgs.push_back(llvm::PointerType::getUnqual(*context));
    FunctionType* printfType = FunctionType::get(Type::getInt32Ty(*context), printfArgs, true);
    Function* printfFunc = Function::Create(printfType, Function::ExternalLinkage, "printf", module.get());

    // scanf
    std::vector<Type*> scanfArgs;
    scanfArgs.push_back(llvm::PointerType::getUnqual(*context));
    FunctionType* scanfType = FunctionType::get(Type::getInt32Ty(*context), scanfArgs, true);
    Function* scanfFunc = Function::Create(scanfType, Function::ExternalLinkage, "scanf", module.get());

    // print_int(int)
    FunctionType* printIntType = FunctionType::get(Type::getVoidTy(*context), {Type::getInt64Ty(*context)}, false);
    Function* printIntFunc = Function::Create(printIntType, Function::ExternalLinkage, "print", module.get());
    BasicBlock* printIntBB = BasicBlock::Create(*context, "entry", printIntFunc);
    IRBuilder<> builder(printIntBB);

    Value* formatStr = builder.CreateGlobalStringPtr("%lld\n");
    builder.CreateCall(printfFunc, {formatStr, printIntFunc->getArg(0)});
    builder.CreateRetVoid();

    // print_float(float)
    FunctionType* printFloatType = FunctionType::get(Type::getVoidTy(*context), {Type::getDoubleTy(*context)}, false);
    Function* printFloatFunc = Function::Create(printFloatType, Function::ExternalLinkage, "print_float", module.get());
    BasicBlock* printFloatBB = BasicBlock::Create(*context, "entry", printFloatFunc);
    IRBuilder<> builderF(printFloatBB);

    Value* formatStrF = builderF.CreateGlobalStringPtr("%f\n");
    builderF.CreateCall(printfFunc, {formatStrF, printFloatFunc->getArg(0)});
    builderF.CreateRetVoid();

    // read_int() -> int
    FunctionType* readIntType = FunctionType::get(Type::getInt64Ty(*context), false);
    Function* readIntFunc = Function::Create(readIntType, Function::ExternalLinkage, "read", module.get());
    BasicBlock* readIntBB = BasicBlock::Create(*context, "entry", readIntFunc);
    IRBuilder<> readBuilder(readIntBB);

    Value* readFormatStr = readBuilder.CreateGlobalStringPtr("%lld");
    AllocaInst* valAlloc = readBuilder.CreateAlloca(Type::getInt64Ty(*context));
    readBuilder.CreateCall(scanfFunc, {readFormatStr, valAlloc});
    Value* loadedVal = readBuilder.CreateLoad(Type::getInt64Ty(*context), valAlloc);
    readBuilder.CreateRet(loadedVal);
}

Value* ProgramNode::codegen(CodeGenContext& ctx) {
    for (auto& func : functions) {
        func->codegen(ctx);
    }
    return nullptr;
}

Value* IntNode::codegen(CodeGenContext& ctx) {
    return ConstantInt::get(*ctx.context, APInt(64, value, true));
}

Value* FloatNode::codegen(CodeGenContext& ctx) {
    return ConstantFP::get(*ctx.context, APFloat(value));
}

Value* IdentifierNode::codegen(CodeGenContext& ctx) {
    AllocaInst* alloca = ctx.namedValues[name];
    if (!alloca) {
        std::cerr << "Unknown variable name: " << name << std::endl;
        return nullptr;
    }
    return ctx.builder->CreateLoad(alloca->getAllocatedType(), alloca, name.c_str());
}

Value* BinaryOpNode::codegen(CodeGenContext& ctx) {
    Value* L = lhs->codegen(ctx);
    Value* R = rhs->codegen(ctx);
    if (!L || !R) return nullptr;

    bool isFloat = L->getType()->isDoubleTy() || R->getType()->isDoubleTy();
    if (isFloat) {
        if (L->getType()->isIntegerTy()) L = ctx.builder->CreateSIToFP(L, Type::getDoubleTy(*ctx.context), "sitofp");
        if (R->getType()->isIntegerTy()) R = ctx.builder->CreateSIToFP(R, Type::getDoubleTy(*ctx.context), "sitofp");
    }

    switch (op) {
        case T_PLUS:
            return isFloat ? ctx.builder->CreateFAdd(L, R, "addtmp") : ctx.builder->CreateAdd(L, R, "addtmp");
        case T_MINUS:
            return isFloat ? ctx.builder->CreateFSub(L, R, "subtmp") : ctx.builder->CreateSub(L, R, "subtmp");
        case T_MUL:
            return isFloat ? ctx.builder->CreateFMul(L, R, "multmp") : ctx.builder->CreateMul(L, R, "multmp");
        case T_DIV:
            return isFloat ? ctx.builder->CreateFDiv(L, R, "divtmp") : ctx.builder->CreateSDiv(L, R, "divtmp");
        case T_EQ:
            return isFloat ? ctx.builder->CreateFCmpOEQ(L, R, "cmptmp") : ctx.builder->CreateICmpEQ(L, R, "cmptmp");
        case T_NEQ:
            return isFloat ? ctx.builder->CreateFCmpONE(L, R, "cmptmp") : ctx.builder->CreateICmpNE(L, R, "cmptmp");
        case T_LT:
            return isFloat ? ctx.builder->CreateFCmpOLT(L, R, "cmptmp") : ctx.builder->CreateICmpSLT(L, R, "cmptmp");
        case T_LTE:
            return isFloat ? ctx.builder->CreateFCmpOLE(L, R, "cmptmp") : ctx.builder->CreateICmpSLE(L, R, "cmptmp");
        case T_GT:
            return isFloat ? ctx.builder->CreateFCmpOGT(L, R, "cmptmp") : ctx.builder->CreateICmpSGT(L, R, "cmptmp");
        case T_GTE:
            return isFloat ? ctx.builder->CreateFCmpOGE(L, R, "cmptmp") : ctx.builder->CreateICmpSGE(L, R, "cmptmp");
        default:
            std::cerr << "Invalid binary operator" << std::endl;
            return nullptr;
    }
}

Value* CallNode::codegen(CodeGenContext& ctx) {
    std::string funcName = callee;

    std::vector<Value*> argsV;
    for (unsigned i = 0, e = args.size(); i != e; ++i) {
        argsV.push_back(args[i]->codegen(ctx));
        if (!argsV.back()) return nullptr;
    }

    // Quick overload for print
    if (funcName == "print" && args.size() == 1) {
        // If we want a quick hack for print
        if (argsV[0] && argsV[0]->getType()->isDoubleTy()) {
            funcName = "print_float";
        }
    }

    Function* calleeF = ctx.module->getFunction(funcName);
    if (!calleeF) {
        std::cerr << "Unknown function referenced: " << funcName << std::endl;
        return nullptr;
    }

    if (calleeF->arg_size() != args.size() && !calleeF->isVarArg()) {
        std::cerr << "Incorrect number of arguments passed" << std::endl;
        return nullptr;
    }

    return ctx.builder->CreateCall(calleeF, argsV, "calltmp");
}

Value* BlockNode::codegen(CodeGenContext& ctx) {
    Value* lastVal = nullptr;
    for (auto& stmt : statements) {
        lastVal = stmt->codegen(ctx);
    }
    return lastVal;
}

Value* ExprStmtNode::codegen(CodeGenContext& ctx) {
    return expr->codegen(ctx);
}

Value* VarDeclNode::codegen(CodeGenContext& ctx) {
    Function* TheFunction = ctx.currentFunction;
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());

    Type* t = nullptr;
    if (type == "int") t = Type::getInt64Ty(*ctx.context);
    else if (type == "float") t = Type::getDoubleTy(*ctx.context);
    else {
        std::cerr << "Unknown type: " << type << std::endl;
        return nullptr;
    }

    AllocaInst* Alloca = TmpB.CreateAlloca(t, 0, name.c_str());
    ctx.namedValues[name] = Alloca;
    return Alloca;
}

Value* AssignmentNode::codegen(CodeGenContext& ctx) {
    Value* val = expr->codegen(ctx);
    if (!val) return nullptr;

    AllocaInst* variable = ctx.namedValues[name];
    if (!variable) {
        std::cerr << "Unknown variable name: " << name << std::endl;
        return nullptr;
    }

    ctx.builder->CreateStore(val, variable);
    return val;
}

Value* IfNode::codegen(CodeGenContext& ctx) {
    Value* CondV = condition->codegen(ctx);
    if (!CondV) return nullptr;

    // Convert condition to a bool by comparing non-equal to 0.0.
    if (CondV->getType()->isDoubleTy()) {
        CondV = ctx.builder->CreateFCmpONE(CondV, ConstantFP::get(*ctx.context, APFloat(0.0)), "ifcond");
    } else if (CondV->getType()->isIntegerTy()) {
        CondV = ctx.builder->CreateICmpNE(CondV, ConstantInt::get(*ctx.context, APInt(CondV->getType()->getIntegerBitWidth(), 0)), "ifcond");
    }

    Function* TheFunction = ctx.currentFunction;

    BasicBlock* ThenBB = BasicBlock::Create(*ctx.context, "then", TheFunction);
    BasicBlock* ElseBB = BasicBlock::Create(*ctx.context, "else");
    BasicBlock* MergeBB = BasicBlock::Create(*ctx.context, "ifcont");

    ctx.builder->CreateCondBr(CondV, ThenBB, ElseBB);

    // Then
    ctx.builder->SetInsertPoint(ThenBB);
    thenBlock->codegen(ctx);
    if (!ctx.builder->GetInsertBlock()->getTerminator()) {
        ctx.builder->CreateBr(MergeBB);
    }
    ThenBB = ctx.builder->GetInsertBlock();

    // Else
    TheFunction->insert(TheFunction->end(), ElseBB);
    ctx.builder->SetInsertPoint(ElseBB);
    if (elseBlock) {
        elseBlock->codegen(ctx);
    }
    if (!ctx.builder->GetInsertBlock()->getTerminator()) {
        ctx.builder->CreateBr(MergeBB);
    }
    ElseBB = ctx.builder->GetInsertBlock();

    // Merge
    TheFunction->insert(TheFunction->end(), MergeBB);
    ctx.builder->SetInsertPoint(MergeBB);

    return nullptr;
}

Value* WhileNode::codegen(CodeGenContext& ctx) {
    Function* TheFunction = ctx.currentFunction;

    BasicBlock* CondBB = BasicBlock::Create(*ctx.context, "cond", TheFunction);
    BasicBlock* LoopBB = BasicBlock::Create(*ctx.context, "loop", TheFunction);
    BasicBlock* AfterBB = BasicBlock::Create(*ctx.context, "afterloop", TheFunction);

    ctx.builder->CreateBr(CondBB);
    ctx.builder->SetInsertPoint(CondBB);

    Value* CondV = condition->codegen(ctx);
    if (!CondV) return nullptr;
    if (CondV->getType()->isDoubleTy()) {
        CondV = ctx.builder->CreateFCmpONE(CondV, ConstantFP::get(*ctx.context, APFloat(0.0)), "whilecond");
    } else if (CondV->getType()->isIntegerTy()) {
        CondV = ctx.builder->CreateICmpNE(CondV, ConstantInt::get(*ctx.context, APInt(CondV->getType()->getIntegerBitWidth(), 0)), "whilecond");
    }

    ctx.builder->CreateCondBr(CondV, LoopBB, AfterBB);

    ctx.builder->SetInsertPoint(LoopBB);
    block->codegen(ctx);
    if (!ctx.builder->GetInsertBlock()->getTerminator()) {
        ctx.builder->CreateBr(CondBB);
    }

    ctx.builder->SetInsertPoint(AfterBB);

    return nullptr;
}

Value* ReturnNode::codegen(CodeGenContext& ctx) {
    if (expr) {
        Value* V = expr->codegen(ctx);
        if (!V) return nullptr;
        return ctx.builder->CreateRet(V);
    }
    return ctx.builder->CreateRetVoid();
}

Value* FunctionNode::codegen(CodeGenContext& ctx) {
    std::vector<Type*> argTypes;
    for (const auto& arg : args) {
        if (arg.first == "int") argTypes.push_back(Type::getInt64Ty(*ctx.context));
        else if (arg.first == "float") argTypes.push_back(Type::getDoubleTy(*ctx.context));
    }

    Type* retT = Type::getVoidTy(*ctx.context);
    if (returnType == "int") retT = Type::getInt64Ty(*ctx.context);
    else if (returnType == "float") retT = Type::getDoubleTy(*ctx.context);

    FunctionType* FT = FunctionType::get(retT, argTypes, false);
    Function* F = Function::Create(FT, Function::ExternalLinkage, name, ctx.module.get());

    unsigned Idx = 0;
    for (auto& Arg : F->args()) {
        Arg.setName(args[Idx++].second);
    }

    BasicBlock* BB = BasicBlock::Create(*ctx.context, "entry", F);
    ctx.builder->SetInsertPoint(BB);

    ctx.namedValues.clear();
    ctx.currentFunction = F;

    // Allocate args
    Idx = 0;
    for (auto& Arg : F->args()) {
        AllocaInst* Alloca = ctx.builder->CreateAlloca(Arg.getType(), 0, Arg.getName());
        ctx.builder->CreateStore(&Arg, Alloca);
        ctx.namedValues[std::string(Arg.getName())] = Alloca;
    }

    block->codegen(ctx);

    // Ensure terminal return if not present
    if (!ctx.builder->GetInsertBlock()->getTerminator()) {
        if (returnType == "void" || returnType.empty()) {
            ctx.builder->CreateRetVoid();
        } else {
            if (returnType == "int") ctx.builder->CreateRet(ConstantInt::get(*ctx.context, APInt(64, 0)));
            else ctx.builder->CreateRet(ConstantFP::get(*ctx.context, APFloat(0.0)));
        }
    }

    verifyFunction(*F);

    return F;
}
