#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>
#include <string>

#include "TokenType.h"
using std::ostream;

class Token {
public:
	Token() {
		type = TOK_UNKNOWN;
		value = "";
	};

	Token(TokenType type) : type(type), value("") {}

	Token(TokenType type, const string& value) : type(type), value(value) {}

	Token& operator=(const Token& token);

	TokenType getType() const;
	string getValue() const;

	~Token();

	inline bool operator ==(const Token& t) {
		return value == t.value &&  type == t.type;
	}

	inline bool operator == (const TokenType type) {
		return this->type == type;
	}

	friend ostream& operator<<(ostream& out, const Token& t) {
		out << "(" << tok_name(t.getType());
		if(t.getValue() == "") out << ")";
		else out << ", " << t.getValue() << ")";
		return out;
	}

private:
	TokenType type;
	string value;
};



#endif 