%{
#include "ast.hh"
#include <iostream>
#include <vector>

extern int yylex();
extern int yylineno;
void yyerror(const char *s) {
    std::cerr << "Error at line " << yylineno << ": " << s << std::endl;
}

extern std::unique_ptr<ProgramNode> programBlock;
%}

%union {
    std::string *string;
    ExprNode *expr;
    StmtNode *stmt;
    BlockNode *block;
    FunctionNode *func;
    std::vector<std::unique_ptr<StmtNode>> *stmt_vec;
    std::vector<std::unique_ptr<ExprNode>> *expr_vec;
    std::vector<std::pair<std::string, std::string>> *arg_vec;
}

%token <string> T_IDENTIFIER T_INTEGER T_FLOAT T_STRING
%token T_TYPE_INT T_TYPE_FLOAT T_IF T_ELSE T_WHILE T_RETURN T_DELIMITER
%token T_ASSIGN T_EQ T_NEQ T_LT T_LTE T_GT T_GTE T_PLUS T_MINUS T_MUL T_DIV
%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_COMMA

%type <stmt> stmt
%type <block> block
%type <expr> expr
%type <func> func_decl
%type <stmt_vec> stmts
%type <expr_vec> call_args
%type <arg_vec> func_args func_args_list
%type <string> type_spec

%left T_EQ T_NEQ T_LT T_LTE T_GT T_GTE
%left T_PLUS T_MINUS
%left T_MUL T_DIV

%start program

%%

program:
      program func_decl { programBlock->functions.push_back(std::unique_ptr<FunctionNode>($2)); }
    | program T_DELIMITER
    | /* empty */ { programBlock = std::make_unique<ProgramNode>(); }
    ;

func_decl:
      type_spec T_IDENTIFIER T_LPAREN func_args T_RPAREN block {
          $$ = new FunctionNode(*$1, *$2, *$4, std::unique_ptr<BlockNode>($6));
          delete $1; delete $2; delete $4;
      }
    | T_IDENTIFIER T_LPAREN func_args T_RPAREN block {
          $$ = new FunctionNode("void", *$1, *$3, std::unique_ptr<BlockNode>($5));
          delete $1; delete $3;
      }
    ;

type_spec:
      T_TYPE_INT { $$ = new std::string("int"); }
    | T_TYPE_FLOAT { $$ = new std::string("float"); }
    ;

func_args:
      /* empty */ { $$ = new std::vector<std::pair<std::string, std::string>>(); }
    | func_args_list { $$ = $1; }
    ;

func_args_list:
      type_spec T_IDENTIFIER {
          $$ = new std::vector<std::pair<std::string, std::string>>();
          $$->push_back({*$1, *$2});
          delete $1; delete $2;
      }
    | func_args_list T_COMMA type_spec T_IDENTIFIER {
          $1->push_back({*$3, *$4});
          $$ = $1;
          delete $3; delete $4;
      }
    ;

block:
      T_LBRACE stmts T_RBRACE {
          $$ = new BlockNode();
          $$->statements = std::move(*$2);
          delete $2;
      }
    | T_LBRACE T_RBRACE {
          $$ = new BlockNode();
      }
    ;

stmts:
      stmt {
          $$ = new std::vector<std::unique_ptr<StmtNode>>();
          if ($1) $$->push_back(std::unique_ptr<StmtNode>($1));
      }
    | stmts stmt {
          if ($2) $1->push_back(std::unique_ptr<StmtNode>($2));
          $$ = $1;
      }
    ;

stmt:
      type_spec T_IDENTIFIER T_DELIMITER {
          $$ = new VarDeclNode(*$1, *$2);
          delete $1; delete $2;
      }
    | T_IDENTIFIER T_ASSIGN expr T_DELIMITER {
          $$ = new AssignmentNode(*$1, std::unique_ptr<ExprNode>($3));
          delete $1;
      }
    | T_IF expr block {
          $$ = new IfNode(std::unique_ptr<ExprNode>($2), std::unique_ptr<BlockNode>($3), nullptr);
      }
    | T_IF expr block T_ELSE block {
          $$ = new IfNode(std::unique_ptr<ExprNode>($2), std::unique_ptr<BlockNode>($3), std::unique_ptr<BlockNode>($5));
      }
    | T_WHILE T_LPAREN expr T_RPAREN block {
          $$ = new WhileNode(std::unique_ptr<ExprNode>($3), std::unique_ptr<BlockNode>($5));
      }
    | T_RETURN expr T_DELIMITER {
          $$ = new ReturnNode(std::unique_ptr<ExprNode>($2));
      }
    | T_RETURN T_DELIMITER {
          $$ = new ReturnNode(nullptr);
      }
    | expr T_DELIMITER {
          $$ = new ExprStmtNode(std::unique_ptr<ExprNode>($1));
      }
    | T_DELIMITER {
          $$ = nullptr;
      }
    ;

expr:
      T_IDENTIFIER { $$ = new IdentifierNode(*$1); delete $1; }
    | T_INTEGER { $$ = new IntNode(std::stoll(*$1)); delete $1; }
    | T_FLOAT { $$ = new FloatNode(std::stod(*$1)); delete $1; }
    | T_STRING { $$ = new StringNode(*$1); delete $1; }
    | expr T_PLUS expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_PLUS, std::unique_ptr<ExprNode>($3)); }
    | expr T_MINUS expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_MINUS, std::unique_ptr<ExprNode>($3)); }
    | expr T_MUL expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_MUL, std::unique_ptr<ExprNode>($3)); }
    | expr T_DIV expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_DIV, std::unique_ptr<ExprNode>($3)); }
    | expr T_EQ expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_EQ, std::unique_ptr<ExprNode>($3)); }
    | expr T_NEQ expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_NEQ, std::unique_ptr<ExprNode>($3)); }
    | expr T_LT expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_LT, std::unique_ptr<ExprNode>($3)); }
    | expr T_LTE expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_LTE, std::unique_ptr<ExprNode>($3)); }
    | expr T_GT expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_GT, std::unique_ptr<ExprNode>($3)); }
    | expr T_GTE expr { $$ = new BinaryOpNode(std::unique_ptr<ExprNode>($1), T_GTE, std::unique_ptr<ExprNode>($3)); }
    | T_LPAREN expr T_RPAREN { $$ = $2; }
    | T_IDENTIFIER T_LPAREN call_args T_RPAREN {
          $$ = new CallNode(*$1, std::move(*$3));
          delete $1; delete $3;
      }
    ;

call_args:
      /* empty */ { $$ = new std::vector<std::unique_ptr<ExprNode>>(); }
    | expr {
          $$ = new std::vector<std::unique_ptr<ExprNode>>();
          $$->push_back(std::unique_ptr<ExprNode>($1));
      }
    | call_args T_COMMA expr {
          $1->push_back(std::unique_ptr<ExprNode>($3));
          $$ = $1;
      }
    ;

%%
