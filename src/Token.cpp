#include "../include/frontend/Token.h"

Token::~Token() {
	value = "";
	type = TOK_UNKNOWN;
}

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