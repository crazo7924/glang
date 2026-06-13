#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class CodeGenContext;
namespace llvm {
    class Value;
    class Type;
}

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual llvm::Value* codegen(CodeGenContext& context) = 0;
};

class ExprNode : public ASTNode {
public:
    virtual llvm::Value* codegen(CodeGenContext& context) = 0;
};

class StmtNode : public ASTNode {
public:
    virtual llvm::Value* codegen(CodeGenContext& context) = 0;
};

class IntNode : public ExprNode {
public:
    long long value;
    IntNode(long long value) : value(value) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class FloatNode : public ExprNode {
public:
    double value;
    FloatNode(double value) : value(value) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class StringNode : public ExprNode {
private:
    std::string sanitizeString(const std::string& raw) {
        if (raw.length() < 2 || raw.front() != '"' || raw.back() != '"') {
            return raw;
        }
        std::string result;
        result.reserve(raw.length() - 2);
        for (size_t i = 1; i < raw.length() - 1; ++i) {
            if (raw[i] == '\\') {
                if (i + 1 >= raw.length() - 1) {
                    std::cerr << "Warning: Escape character '\\' at end of string literal." << std::endl;
                    result += '\\';
                    break;
                }
                char next = raw[++i];
                switch (next) {
                    case 'n': result += '\n'; break;
                    case 't': result += '\t'; break;
                    case 'r': result += '\r'; break;
                    case '\\': result += '\\'; break;
                    case '"': result += '"'; break;
                    case '\'': result += '\''; break;
                    case '0': result += '\0'; break;
                    default:
                        std::cerr << "Warning: Unknown escape sequence '\\" << next << "'." << std::endl;
                        result += '\\';
                        result += next;
                        break;
                }
            } else {
                result += raw[i];
            }
        }
        return result;
    }
public:
    std::string value;
    StringNode(const std::string& raw_value) {
        value = sanitizeString(raw_value);
    }
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class IdentifierNode : public ExprNode {
public:
    std::string name;
    IdentifierNode(const std::string& name) : name(name) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class BinaryOpNode : public ExprNode {
public:
    int op; // using token values
    std::unique_ptr<ExprNode> lhs;
    std::unique_ptr<ExprNode> rhs;
    BinaryOpNode(std::unique_ptr<ExprNode> lhs, int op, std::unique_ptr<ExprNode> rhs)
        : lhs(std::move(lhs)), op(op), rhs(std::move(rhs)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class CallNode : public ExprNode {
public:
    std::string callee;
    std::vector<std::unique_ptr<ExprNode>> args;
    CallNode(const std::string& callee, std::vector<std::unique_ptr<ExprNode>> args)
        : callee(callee), args(std::move(args)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class BlockNode : public StmtNode {
public:
    std::vector<std::unique_ptr<StmtNode>> statements;
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class ExprStmtNode : public StmtNode {
public:
    std::unique_ptr<ExprNode> expr;
    ExprStmtNode(std::unique_ptr<ExprNode> expr) : expr(std::move(expr)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class VarDeclNode : public StmtNode {
public:
    std::string type;
    std::string name;
    VarDeclNode(const std::string& type, const std::string& name)
        : type(type), name(name) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class AssignmentNode : public StmtNode {
public:
    std::string name;
    std::unique_ptr<ExprNode> expr;
    AssignmentNode(const std::string& name, std::unique_ptr<ExprNode> expr)
        : name(name), expr(std::move(expr)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class IfNode : public StmtNode {
public:
    std::unique_ptr<ExprNode> condition;
    std::unique_ptr<BlockNode> thenBlock;
    std::unique_ptr<BlockNode> elseBlock;
    IfNode(std::unique_ptr<ExprNode> condition, std::unique_ptr<BlockNode> thenBlock, std::unique_ptr<BlockNode> elseBlock = nullptr)
        : condition(std::move(condition)), thenBlock(std::move(thenBlock)), elseBlock(std::move(elseBlock)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class WhileNode : public StmtNode {
public:
    std::unique_ptr<ExprNode> condition;
    std::unique_ptr<BlockNode> block;
    WhileNode(std::unique_ptr<ExprNode> condition, std::unique_ptr<BlockNode> block)
        : condition(std::move(condition)), block(std::move(block)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class ReturnNode : public StmtNode {
public:
    std::unique_ptr<ExprNode> expr;
    ReturnNode(std::unique_ptr<ExprNode> expr = nullptr) : expr(std::move(expr)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class FunctionNode : public ASTNode {
public:
    std::string returnType;
    std::string name;
    std::vector<std::pair<std::string, std::string>> args; // type, name
    std::unique_ptr<BlockNode> block;

    FunctionNode(const std::string& returnType, const std::string& name,
                 std::vector<std::pair<std::string, std::string>> args,
                 std::unique_ptr<BlockNode> block)
        : returnType(returnType), name(name), args(std::move(args)), block(std::move(block)) {}
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};

class ProgramNode : public ASTNode {
public:
    std::vector<std::unique_ptr<FunctionNode>> functions;
    virtual llvm::Value* codegen(CodeGenContext& context) override;
};
