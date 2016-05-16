//
// Crmatched by gustavo on 15/05/16.
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

inline bool Syntax::checkToken(long t) {
    return  tok.getType() & t;
}

void Syntax::matchToken(long t){
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
    findIdentList();
    matchToken(TOK_IS);
    findType();
}

void Syntax::findIdentList(){
    matchToken(TOK_ID);
    while(checkToken(TOK_COMMA)){
        matchToken(TOK_COMMA);
        matchToken(TOK_ID);
    }
}

void Syntax::findType(){
    matchToken(TOK_INT | TOK_STRING);
}

void Syntax::findStmtLst(){
    findStmt();
    matchToken(TOK_SEMICOLON);
    while(!checkToken(TOK_END | TOK_WHILE | TOK_ELSE)){
        findStmt();
        matchToken(TOK_SEMICOLON);
    }
}

void Syntax::findStmt(){
    switch (tok.getType()){
        case TOK_ID:
            findAssignStmt();
            break;
        case TOK_IF:
            findIfStmt();
            break;
        case TOK_DO:
            findDoWhileStmt();
            break;
        case TOK_IN:
            findReadStmt();
            break;
        case TOK_OUT:
            findWriteStmt();
            break;
        default:
            error();
    }
}

void Syntax::findAssignStmt(){
    matchToken(TOK_ID);
    matchToken(TOK_ASSIGN);
    findSimpleExpr();
}

void Syntax::findIfStmt(){
    matchToken(TOK_IF);
    findExpression();
    matchToken(TOK_THEN);
    findStmtLst();
    if(checkToken(TOK_ELSE)){
        matchToken(TOK_ELSE);
        findStmtLst();
    }
    matchToken(TOK_END);
}

void Syntax::findDoWhileStmt(){
    matchToken(TOK_DO);
    findStmtLst();
    matchToken(TOK_WHILE);
    findExpression();
}

void Syntax::findReadStmt(){
    matchToken(TOK_IN);
    matchToken(TOK_PAR_OPEN);
    matchToken(TOK_ID);
    matchToken(TOK_PAR_CLOSE);
}
void Syntax::findWriteStmt(){
    matchToken(TOK_OUT);
    matchToken(TOK_PAR_OPEN);
    findSimpleExpr();
    matchToken(TOK_PAR_CLOSE);
}

void Syntax::findExpression();
void Syntax::findSimpleExpr();
void Syntax::findTerm();

void Syntax::findFactorA(){
    if(checkToken(TOK_NOT)){
        matchToken(TOK_NOT);
        findFactor();
    } else if (checkToken(TOK_SUB)){
        matchToken(TOK_SUB);
        findFactor();
    } else findFactor();
}


void Syntax::findFactor(){
    if(checkToken(TOK_PAR_OPEN)) {
        matchToken(TOK_PAR_OPEN);
        findExpression();
        matchToken(TOK_PAR_CLOSE);
    } else matchToken(TOK_ID | TOK_CONST_STR | TOK_CONST_INT);

}


// ---------- Just-One-Token Methods:
void Syntax::findRelop(){
    matchToken(TOK_EQUALS | TOK_GT | TOK_GTE | TOK_LT | TOK_LTE);
}

void Syntax::findAddop(){
    matchToken(TOK_ADD | TOK_SUB | TOK_OR);
}

void Syntax::findMulop(){
    matchToken(TOK_MULT | TOK_AND | TOK_DIV);
}

void Syntax::findConstant(){
    matchToken(TOK_CONST_INT | TOK_CONST_STR);
}

void Syntax::findIntegerConst(){
    matchToken(TOK_CONST_INT);
}

void Syntax::findLiteral(){
    matchToken(TOK_LT);
}

void Syntax::findIdentifier(){
    matchToken(TOK_ID);
}