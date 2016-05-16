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
    if (tok.getType() & t) advance();
    else error(t, tok);
}

/*    else {
        list<TokenType> tokens = listTokens(t);

        stringstream errorbuf;

        errorbuf << "Syntax error on line " << (parser->getLines()+1) << ":"
        << (parser->getColumns()+1) << ": Expected ";


        for(list<TokenType>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            errorbuf << token_name(*it) + ", ";
        }

        errorbuf << "but found " << token_name(lexeme.type) << " ("  << lexeme.token << ")";

        throw errorbuf.str();
    }
*/

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

void Syntax::procFactorA(){
    if(tok == TOK_NOT){
        eatToken(TOK_NOT);
        procFactor();
    } else if (tok == TOK_SUB){
        eatToken(TOK_SUB);
        procFactor();
    } else procFactor();
}


void Syntax::procFactor(){
    if(tok==TOK_PAR_OPEN) {
        eatToken(TOK_PAR_OPEN);
        procExpression();
        eatToken(TOK_PAR_CLOSE);
    } else eatToken(TOK_ID | TOK_CONST_STR | TOK_CONST_INT);

}


void Syntax::procRelop(){
    eatToken(TOK_EQUALS | TOK_GT | TOK_GTE | TOK_LT | TOK_LTE);
}

void Syntax::procAddop(){
    eatToken(TOK_ADD | TOK_SUB | TOK_OR);
}

void Syntax::procMulop(){
    eatToken(TOK_MULT | TOK_AND | TOK_DIV);
}


// ---------- Just-One-Token Methods:
void Syntax::procConstant(){
    eatToken(TOK_CONST_INT | TOK_CONST_STR);
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