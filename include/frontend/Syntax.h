//
// Created by gustavo on 15/05/16.
//

#ifndef _SYNTAX_H
#define _SYNTAX_H


#include <exception>
#include <string>
#include <vector>

#include "backend/CodeGenerator.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Scanner.h"
#include "frontend/Scope.h"
#include "frontend/Symbol.h"
#include "frontend/Token.h"
#include "frontend/TokenType.h"


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
    Syntax(Scanner* s, CodeGenerator* gen) : scanner(s), gen(gen) {
        scope = new Scope();
        advance();
    }

    ~Syntax() {}

    /**
     * \brief Analyse a program
     */
    void analyse();

private:

    Token tok;
    Scanner* scanner;
    Scope* scope;
    CodeGenerator* gen;

    inline bool checkToken(long t) {
        return  tok.getType() & t;
    }

    inline Token matchToken(long t){
        Token ret = tok;

        if (tok.getType() & t) advance();
        else error(t, tok);

        return ret;
    }

    inline void advance(){
        tok = scanner->nextToken(); //lê próximo token
    }

    void findProgram();
    void findDeclList();
    void findDecl();
    vector<Token> findIdentList();
    void findType();
    vector<Statement*> findStmtLst();
    Statement* findStmt();
    Statement* findAssignStmt();
    Statement* findIfStmt();
    Statement* findDoWhileStmt();
    Statement* findReadStmt();
    Statement* findWriteStmt();
    Expression* findExpression();
    Expression* findSimpleExpr();
    Expression* findTerm();
    Expression* findFactorA();
    Expression* findFactor();

    void error();
    void error(long tok);
    void error(long t, Token tok);

    /// it's a friend class because we need to test the private methods
    friend class SyntaxTest;
};


#endif //PAS_C_SYNTAX_H
