//
// Crmatched by gustavo on 15/05/16.
//

#include "Util.h"

#include "exception/SyntaxError.h"
#include "frontend/Syntax.h"
#include "frontend/Scanner.h"
#include "frontend/Token.h"
#include "frontend/TokenType.h"
#include "frontend/Type.h"

#include "frontend/stmt/AddExpr.h"
#include "frontend/stmt/AndExpr.h"
#include "frontend/stmt/CompExpr.h"
#include "frontend/stmt/ConstIntExpr.h"
#include "frontend/stmt/ConstStrExpr.h"
#include "frontend/stmt/DivExpr.h"
#include "frontend/stmt/InvExpr.h"
#include "frontend/stmt/MultExpr.h"
#include "frontend/stmt/NotExpr.h"
#include "frontend/stmt/OrExpr.h"
#include "frontend/stmt/SubExpr.h"
#include "frontend/stmt/VarExpr.h"

#include "frontend/stmt/IfStmt.h"
#include "frontend/stmt/WhileStmt.h"
#include "frontend/stmt/AssignStmt.h"
#include "frontend/stmt/ReadStmt.h"
#include "frontend/stmt/WriteStmt.h"


#include <iostream>
using std::cout;
using std::endl;

void Syntax::analyse(){
    findProgram();
}

// ---------- Token Consumer methods:



void Syntax::error(long t, Token tok) {
    //vector<TokenType> expected = unmask(t);

    throw SyntaxError(scanner->getLineCount(), scanner->getColumnCount(), t, tok);
}

void Syntax::error() {
    error(0, Token());
}

// ---------- Non-Terminal consumer methods:

void Syntax::findProgram(){
    if(checkToken(TOK_VAR)){
        matchToken(TOK_VAR);
        findDeclList();
    }
    matchToken(TOK_BEGIN);
    findStmtLst();
    matchToken(TOK_END);
}

void Syntax::findDeclList(){
    findDecl();
    matchToken(TOK_SEMICOLON);
    while(!checkToken(TOK_BEGIN)){
        findDecl();
        matchToken(TOK_SEMICOLON);
    }
}

void Syntax::findDecl(){
    vector<Token> varList = findIdentList();
    matchToken(TOK_IS);
    Token type = matchToken(TOK_INT | TOK_STRING);

    vector<Token>::iterator it = varList.begin();

    VarType varType = type.getType() & TOK_INT ? NATIVE_INT : NATIVE_STR;

    for(; it != varList.end(); ++it) {
        scope->addSymbol(*it,  new Symbol(it->getValue(), 0, varType));
    }
}

vector<Token> Syntax::findIdentList(){
    vector<Token> varList;

    if(checkToken(TOK_ID)) {
        Token tok = matchToken(TOK_ID);
        varList.push_back(tok);
    }

    while(checkToken(TOK_COMMA)){
        matchToken(TOK_COMMA);
     
        if(checkToken(TOK_ID)) {         
            Token tok = matchToken(TOK_ID);
            varList.push_back(tok);
        }
    }

    return varList;
}

void Syntax::findType(){
    matchToken(TOK_INT | TOK_STRING);
}

vector<Statement*> Syntax::findStmtLst(){
    
    vector<Statement*> stmtList;

    stmtList.push_back(findStmt());

    matchToken(TOK_SEMICOLON);
    while(!checkToken(TOK_END | TOK_WHILE | TOK_ELSE)){
        
        Statement* stmt = findStmt();
        matchToken(TOK_SEMICOLON);
        
        stmtList.push_back(stmt);
    }

    return stmtList;
}

Statement* Syntax::findStmt(){
    
    Statement* stmt;

    switch (tok.getType()){
        case TOK_ID:
            stmt = findAssignStmt();
            break;
        case TOK_IF:
            stmt = findIfStmt();
            break;
        case TOK_DO:
            stmt = findDoWhileStmt();
            break;
        case TOK_IN:
            stmt = findReadStmt();
            break;
        case TOK_OUT:
            stmt = findWriteStmt();
            break;
        default:
            error();
    }

    return stmt;
}

Statement* Syntax::findAssignStmt(){
    Symbol *symbol = scope->find(this->tok);

    matchToken(TOK_ID);
    matchToken(TOK_ASSIGN);
    Expression * expr = findSimpleExpr();

    Statement* stmt = new AssignStmt(this->gen, symbol, expr);

    return stmt;
}

Statement* Syntax::findIfStmt(){
    matchToken(TOK_IF);
    Expression* expr = findExpression();
    matchToken(TOK_THEN);
    

    vector<Statement*>  ifList = findStmtLst();
    vector<Statement*> elseList;

    if(checkToken(TOK_ELSE)){
        matchToken(TOK_ELSE);
        elseList = findStmtLst();
    }
    matchToken(TOK_END);

    Statement* stmt = new IfStmt(gen, expr, ifList);

    return stmt;
}

Statement* Syntax::findDoWhileStmt(){
    matchToken(TOK_DO);
    vector<Statement*> stmtList = findStmtLst();
    matchToken(TOK_WHILE);
    Expression* expr = findExpression();

    Statement* stmt = new WhileStmt(gen, expr, stmtList);
}

Statement* Syntax::findReadStmt(){
    matchToken(TOK_IN);
    matchToken(TOK_PAR_OPEN);

    Symbol *symbol;

    if(checkToken(TOK_ID)) {
        symbol = scope->find(this->tok);
    }

    matchToken(TOK_ID);
    matchToken(TOK_PAR_CLOSE);

    Statement * stmt = new ReadStmt(gen, symbol);
    return stmt;
}


Statement* Syntax::findWriteStmt(){
    matchToken(TOK_OUT);
    matchToken(TOK_PAR_OPEN);
    Expression* expr = findSimpleExpr();
    matchToken(TOK_PAR_CLOSE);

    Statement* stmt = new WriteStmt(gen, expr);
    return stmt;
}

Expression* Syntax::findExpression() {
    Expression* left = findSimpleExpr(), *right;

    if(checkToken(TOK_EQUALS | TOK_GT | TOK_GTE | TOK_LT | TOK_LTE)) {
        matchToken(TOK_EQUALS | TOK_GT | TOK_GTE | TOK_LT | TOK_LTE);
        
        right = findSimpleExpr();
    } else return left;

    return new CompExpr(gen, tok.getType(), left, right);
}

Expression* Syntax::findSimpleExpr() {
    Expression *t1, *t2;
    Token op;

    t1 = findTerm();

    if(checkToken(TOK_SUB | TOK_ADD | TOK_OR)) {    
        op = matchToken(TOK_SUB | TOK_ADD | TOK_OR);
        t2 = findSimpleExpr();
    
    } else return t1;

    Expression *expr = NULL;

    switch(op.getType()) {
        case TOK_ADD:
            expr = new AddExpr(gen, t1, t2);
            break;

        case TOK_SUB:
            expr = new SubExpr(gen, t1, t2);
            break;

        case TOK_OR:
            expr = new OrExpr(gen, t1, t2);
            break;    
    }

    return expr;
}

Expression* Syntax::findTerm() {
    
    Expression *t1, *t2;
    Token op;

    t1 = findFactorA();

    if(checkToken(TOK_DIV | TOK_MULT | TOK_AND)) {
        op = matchToken(TOK_DIV | TOK_MULT | TOK_AND);
        t2 = findTerm();
    } else return t1;


    Expression* expr;

    switch(op.getType()) {

        case TOK_DIV:
            expr = new DivExpr(gen, t1, t2);
            break;

        case TOK_MULT:
            expr = new MultExpr(gen, t1, t2);
            break;

        case TOK_AND:
            expr = new AndExpr(gen, t1, t2);
            break;
    }

    return expr;

}

Expression* Syntax::findFactorA(){
    Expression * expr;

    if(checkToken(TOK_NOT)){
        matchToken(TOK_NOT);
        expr = findFactor();

        expr = new NotExpr(gen, expr);

    } else if (checkToken(TOK_SUB)){
        matchToken(TOK_SUB);
        expr = findFactor();

        expr = new InvExpr(gen, expr);
    } else expr = findFactor();

    return expr;
}


Expression* Syntax::findFactor(){
    Expression *expr;

    if(checkToken(TOK_PAR_OPEN)) {
        matchToken(TOK_PAR_OPEN);
        expr = findExpression();
        matchToken(TOK_PAR_CLOSE);
    } else {
        
        Token tok = matchToken(TOK_ID | TOK_CONST_INT | TOK_CONST_STR);
        
        switch (tok.getType()) {
            case TOK_ID:
                expr = new VarExpr(gen, scope->find(tok));
                break;

            case TOK_CONST_INT:
                expr = new ConstIntExpr(gen, strToInt(tok.getValue()));
                break;

            case TOK_CONST_STR:
                expr = new ConstStrExpr(gen, tok.getValue());
                break;
        }
    }
    return expr;
}

