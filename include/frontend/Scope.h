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

	/**
	 * \brief Open a new scope with the current scope as the father and return the new scope.
	 * Usage: Scope s; s = s->open();
	 */
	Scope* open();

	/**
	 * \brief Close the current scope, destroy all symbols and return the previous scope. Note that if close is called in
	 * 		the root scope, it destroy the scope (set the current scope for NULL), and return NULL.
	 * Usage: Scope s; s = s->close();
	 */
	Scope* close();

	/**
	 * \brief Add a new symbol to the current scope. If the token is already installed, throw an exception.
	 */
	void addSymbol(Token tok, Symbol* sym);

	/**
	 * \brief Search a token in scope tree. If the token isn't installed, throw an exception.
	 */
	Symbol* find(Token tok);
private:
	Scope* prev;
	map<Token, Symbol*, TokenComp> table;

	typedef map<Token, Symbol*, TokenComp>::iterator scope_it;
};

#endif