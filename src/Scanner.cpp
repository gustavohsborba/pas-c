#include "frontend/Token.h"
#include "frontend/TokenType.h"
#include "frontend/Scanner.h"

#include <cstdio>
#include <sstream>
#include <typeinfo>

using std::stringstream;

map<string, Token> Scanner::reservedWords;

#include <iostream>

Scanner::~Scanner() {
	if(string("ifstream") == typeid(*in).name())
		((ifstream*)in)->close();

	delete in;
}

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
	while(peek() == ' ' || peek() == '\n' || peek() == '\t')
		get();

	if(isalpha(peek()))
		return getLiteral();
	else if(isdigit(peek()))
		return getNumerical();
	else if(peek() == '{')
		return getString();
	else
		return getOperator();

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

	if(peek() == ':') {
		get();
		if(peek() == '=') {
			get();
			op = Token(TOK_ASSIGN);
		}
	} else if(peek() == '<') {
		get();
		if(peek() == '=') {
			get();
			op = Token(TOK_LTE);
		}
		else if(peek() == '>') {
			get();
			op = Token(TOK_DIFF);
		} else {
			op = Token(TOK_LT);
		}
	} else if(peek() == '>') {
		get();
		if(peek() == '=') {
			get();
			op = Token(TOK_GTE);
		}
		else {
			op = Token(TOK_GT);
		}
	} else if(peek() == '=') {
		get();
		op = Token(TOK_EQUALS);
	} else if(peek() == ',') {
		get();
		op = Token(TOK_COMMA);
	} else if(get() == ';') {
		get();
		op = Token(TOK_SEMICOLON);
	} else if(peek() == '+') {
		get();
		op = Token(TOK_ADD);
	} else if(peek() == '-') {
		get();
		op = Token(TOK_SUB);
	} else if(peek() == '*') {
		get();
		op = Token(TOK_MULT);
	} else if(peek() == '/') {
		get();
		op = Token(TOK_DIV);
	} else if(peek() == '(') {
		get();
		op = Token(TOK_PAR_OPEN);
	} else if(peek() == ')') {
		get();
		op = Token(TOK_PAR_CLOSE);
	}

	return op;
}


Token Scanner::getLiteral() {
	stringstream s;

	while(isalnum(peek()) || peek() == '_') {
		s << get();
	}
	

	if(reservedWords.count(s.str())) {
		return Token(reservedWords[s.str()]);
	} else if(isalpha(s.str()[0]) && s.str().length() <= MAX_IDENTIFIER_SIZE) {
		return Token(TOK_ID, s.str());
	}



	return Token();
}

Token Scanner::getNumerical() {
	stringstream s;

	if(peek() == '0') {
		s << get();

		return Token(TOK_CONST_INT, s.str());
	}

	while(isdigit(peek())) {
		s << get();
	}

	return Token(TOK_CONST_INT, s.str());
}

Token Scanner::getString() {
	stringstream s;

	if(peek() == '{') {
		get();

		while(peek() != '}') {

			s << get();
		}

		get();

		return Token(TOK_CONST_STR, s.str());
	}

	return Token();
}

char Scanner::get() {

	char c = in->get();

	columnCount++;
	
	if(c == '\n') {
		lineCount++;
		columnCount = 0;
	}

	return c;
}

char Scanner::peek() {
	return in->peek(); 
}