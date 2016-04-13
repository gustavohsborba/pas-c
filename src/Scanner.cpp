#include "frontend/Token.h"
#include "frontend/TokenType.h"
#include "frontend/Scanner.h"


map<string, Token> Scanner::reservedWords;

void Scanner::init() {
	reservedWords["var"] = Token(TOK_VAR);
	reservedWords["begin"] = Token(TOK_BEGIN);
	reservedWords["end"] = Token(TOK_END);
	reservedWords["is"] = Token(TOK_IS);
	reservedWords["if"] = Token(TOK_IF);
	reservedWords["then"] = Token(TOK_THEN);	
	reservedWords["else"] = Token(TOK_ELSE);
	reservedWords["int"] = Token(TOK_INT);
	reservedWords["string"] = Token(TOK_STRING);	
	reservedWords["do"] = Token(TOK_DO);
	reservedWords["while"] = Token(TOK_WHILE);
	reservedWords["in"] = Token(TOK_IN);
	reservedWords["out"] = Token(TOK_OUT);
	reservedWords["not"] = Token(TOK_NOT);
	reservedWords["or"] = Token(TOK_OR);
	reservedWords["and"] = Token(TOK_AND);
}

Token Scanner::nextToken() {
	return Token();
}

long Scanner::getLineCount() {
	return lineCount;
}

long Scanner::getColumnCount() {
	return columnCount;
}

Token Scanner::getOperator() {

	Token op;

	if(in.peek() == ':') {
		in.get();
		if(in.peek() == '=') {
			in.get();
			op = Token(TOK_ASSIGN);
		}
	} else if(in.peek() == '<') {
		in.get();
		if(in.peek() == '=') {
			in.get();
			op = Token(TOK_LTE);
		}
		else if(in.peek() == '>') {
			in.get();
			op = Token(TOK_DIFF);
		} else {
			op = Token(TOK_LT);
		}
	} else if(in.peek() == '>') {
		in.get();
		if(in.peek() == '=') {
			in.get();
			op = Token(TOK_GTE);
		}
		else {
			op = Token(TOK_GT);
		}
	} else if(in.peek() == '=') {
		in.get();
		op = Token(TOK_EQUALS);
	} else if(in.peek() == ',') {
		in.get();
		op = Token(TOK_COMMA);
	} else if(in.get() == ';') {
		in.get();
		op = Token(TOK_SEMICOLON);
	} else if(in.peek() == '+') {
		in.get();
		op = Token(TOK_ADD);
	} else if(in.peek() == '-') {
		in.get();
		op = Token(TOK_SUB);
	} else if(in.peek() == '*') {
		in.get();
		op = Token(TOK_MULT);
	} else if(in.peek() == '/') {
		in.get();
		op = Token(TOK_DIV);
	} else if(in.peek() == '(') {
		in.get();
		op = Token(TOK_PAR_OPEN);
	} else if(in.peek() == ')') {
		in.get();
		op = Token(TOK_PAR_CLOSE);
	}

	return op;
}

Token Scanner::getLiteral() {
	return Token();
}

Token Scanner::getNumerical() {
	return Token();
}