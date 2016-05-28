//
// Created by gustavo on 15/05/16.
//

#ifndef _SYNTAX_H
#define _SYNTAX_H


#include "Token.h"
#include "TokenType.h"
#include "Scanner.h"

using std::string;
using std::exception;

/// Test class declaration
class SyntaxTest;

/**
 * \brief Parser class, should identify valid language constructions and return an syntactic-tree
 */
class Syntax {

public:
    /**
     * \brief construct a valid parser and get the first token
     */
    Syntax(Scanner* s) : scanner(s){
        advance();
    }

    ~Syntax() {}

    /**
     * \brief Analyse a program
     */
    void analyse();

private:

    Scanner* scanner;
    Token tok;

    inline void matchToken(long t);
    inline bool checkToken(long t);
    inline void advance();

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

    /// it's a friend class because we need to test the private methods
    friend class SyntaxTest;
};


#endif //PAS_C_SYNTAX_H
