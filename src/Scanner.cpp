#include "../include/frontend/Token.h"
#include "../include/frontend/TokenType.h"
#include "../include/frontend/Scanner.h"

#include "../include/exception/MalformedIdentifier.h"
#include "../include/exception/UnknownOperator.h"

#include <cstdio>
#include <sstream>
#include <typeinfo>
#include <algorithm>

using std::stringstream;

map<string, Token> Scanner::reservedWords;

#include <iostream>

Scanner::~Scanner() {
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

	if(isalpha(peek()) || peek() == '_')
		return getLiteral();
	else if(isdigit(peek()))
		return getNumerical();
	else if(peek() == '{')
		return getString();
	else if(peek() == EOF)
		return Token(TOK_EOF);
	else if(ispunct(peek()))
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
	} else if(peek() == ';') {
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
	} else {
		string s = " ";
		s[0] = get();
		op=Token(TOK_UNKNOWN, s);
		throw UnknownOperator(op);
	}

	return op;
}

Token Scanner::getLiteral() {
	stringstream ss;

	if(peek() == '_' || isalpha(peek()) )
		ss << get();
	else{
		ss << get();
		throw MalformedIdentifier(Token(TOK_UNKNOWN, ss.str()), UNKNOWN_CHARACTER_SEQUENCE);
	}

	while(isalnum(peek())) {
		ss << get();
	}
	
	string s;
	ss >> s;
	if(reservedWords.count(s)) {
		return Token(reservedWords[s]);
	} else {
		Token t;
		if(isalpha(s[0]))
			t = Token(TOK_ID, s);
		else if(s[0] == '_' && s.length() > 1)
			t = Token(TOK_ID, s);

		if(s.length() > MAX_IDENTIFIER_SIZE)
			throw MalformedIdentifier(t, IDENTIFIER_EXCEEDED_SIZE);
		if((s[0] == '_' && s.length() == 1))
			throw MalformedIdentifier(t, UNKNOWN_CHARACTER_SEQUENCE);

		return t;
	}

	return Token(TOK_UNKNOWN, s);
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