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

    void matchToken(long t);
    inline bool checkToken(long t);
    void advance();

    void findProgram();
    void findDeclList();
    void findDecl();
    void findIdentList();
    void findType();
    void findStmtLst();
    void findStmt();
    void findAssignStmt();
    void findIfStmt();
    void findDoWhileStmt();
    void findReadStmt();
    void findWriteStmt();
    void findExpression();
    void findSimpleExpr();
    void findTerm();
    void findFactorA();
    void findFactor();
    void findRelop();
    void findAddop();
    void findMulop();
    void findConstant();
    void findIntegerConst();
    void findLiteral();
    void findIdentifier();

    void error();
    void error(long tok);
    void error(long t, Token tok);
};


#endif //PAS_C_SYNTAX_H
