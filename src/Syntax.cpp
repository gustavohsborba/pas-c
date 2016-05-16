//
// Created by gustavo on 15/05/16.
//

#include "../include/frontend/Syntax.h"
#include "../include/frontend/Scanner.h"
#include "../include/frontend/Token.h"
#include "../include/frontend/TokenType.h"

Scanner* Syntax::scanner;
Token Syntax::tok;

void Syntax::analyse(){

}


// ---------- Token Consumer methods:

void Syntax::eatToken(TokenType t){
    if (tok==t) advance();
    else error(t, tok);
}
void Syntax::advance(){
    tok = scanner->nextToken(); //lê próximo token
}


// ---------- Non-Terminal consumer methods:

void Syntax::procProgram();
void Syntax::procDeclList();
void Syntax::procDecl();
void Syntax::procIdentList();
void Syntax::procType();
void Syntax::procStmtLst();
void Syntax::procStmt();
void Syntax::procAssignStmt();
void Syntax::procIfStmt();
void Syntax::procCondition();
void Syntax::procDoStmt();
void Syntax::procStmtSuffix();
void Syntax::procReadStmt();
void Syntax::procWriteStmt();
void Syntax::procWritable();
void Syntax::procExpression();
void Syntax::procSimpleExpr();
void Syntax::procTerm();
void Syntax::procFactorA();
void Syntax::procFactor();


void Syntax::procRelop(){
    if(tok == TOK_EQUALS)
        eatToken(TOK_EQUALS);
}

void Syntax::procAddop(){
    if(tok == TOK_ADD)
        eatToken(TOK_ADD);
    else if(tok == TOK_SUB)
        eatToken(TOK_SUB);
    else if(tok == TOK_OR)
        eatToken(TOK_OR);
    else error();
}

void Syntax::procMulop(){
    if(tok == TOK_MULT)
        eatToken(TOK_MULT);
    else if(tok == TOK_AND)
        eatToken(TOK_AND);
    else if(tok == TOK_DIV)
        eatToken(TOK_DIV);
    else error();
}


// ---------- Just-One-Token Methods:
void Syntax::procConstant(){
    if(tok == TOK_CONST_INT)
        procIntegerConst();
    else if (tok == TOK_CONST_STR)
        eatToken(TOK_CONST_STR);
    else error();
}

void Syntax::procIntegerConst(){
    eatToken(TOK_CONST_INT);
}

void Syntax::procLiteral(){
    eatToken(TOK_LT);
}

void Syntax::procIdentifier(){
    eatToken(TOK_ID);
}



// ---------- Unnecessary methods:
void Syntax::procLetter(){

}
void Syntax::procDigit(){

}
void Syntax::procNonzero(){

}
void Syntax::procChar(){

}