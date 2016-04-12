#include "backend/Token.h"

Token& Token::operator=(const Token& token) {
	type = token.type;
	value = token.value;

	return *this;
} 

TokenType Token::getType() const {
	return type;
}

string Token::getValue() const {
	return value;
}

Token::~Token() {
	value = "";
	type = TOK_UNKNOWN;
}