#ifndef _SCOPE_H
#define _SCOPE_H

#include <map>

#include "frontend/Token.h"
#include "frontend/Symbol.h"

using std::map;

typedef struct TokenComp {
	bool operator ()(const Token& a, const Token& b) const {
		return a.getValue() < b.getValue();
	}
}TokenComp;

class Scope {
public:
	Scope() : prev(NULL) {}

	~Scope();

	Scope* open();
	Scope* close();

	void addSymbol(Token tok, Symbol* sym);
	
	Symbol* find(Token tok);
private:
	Scope* prev;
	map<Token, Symbol*, TokenComp> table;

	typedef map<Token, Symbol*, TokenComp>::iterator scope_it;
};

#endif