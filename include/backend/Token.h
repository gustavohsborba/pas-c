#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "TokenType.h"

class Token {
public:
	Token() {
		type = TOK_UNKNOWN;
		value = "";
	};

	Token(TokenType type, const string& value) : type(type), value(value) {}

	Token& operator=(const Token& token);

	TokenType getType() const;
	string getValue() const;

	~Token();

private:
	TokenType type;
	string value;
};

#endif 