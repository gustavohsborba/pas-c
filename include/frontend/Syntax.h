//
// Created by gustavo on 15/05/16.
//

#ifndef PAS_C_SYNTAX_H
#define PAS_C_SYNTAX_H


#include "Token.h"
#include "TokenType.h"
#include "Scanner.h"

using std::string;
using std::exception;

class Syntax {

public:
    Syntax(Scanner* s) : scanner(s){
    }

    ~Syntax() {}

    void analyse();

private:

    Scanner* scanner;
    Token tok;

    void eatToken(TokenType t);
    void advance();

    void procProgram();
    void procDeclList();
    void procDecl();
    void procIdentList();
    void procType();
    void procStmtLst();
    void procStmt();
    void procAssignStmt();
    void procIfStmt();
    void procCondition();
    void procDoStmt();
    void procStmtSuffix();
    void procReadStmt();
    void procWriteStmt();
    void procWritable();
    void procExpression();
    void procSimpleExpr();
    void procTerm();
    void procFactorA();
    void procFactor();
    void procRelop();
    void procAddop();
    void procMulop();
    void procConstant();
    void procIntegerConst();
    void procLiteral();
    void procIdentifier();
    void procLetter();
    void procDigit();
    void procNonzero();
    void procChar();

    void error();
    void error(Token tok);
    void error(TokenType t, Token tok);
};


#endif //PAS_C_SYNTAX_H
