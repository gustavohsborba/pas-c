#include "../include/exception/SymbolAlreadyInstalled.h"
#include "../include/exception/SymbolNotFound.h"
#include "../include/frontend/Scope.h"
#include "../include/frontend/Symbol.h"
#include "../include/frontend/Token.h"

Scope::~Scope() {
	for (scope_it it = table.begin(); it != table.end(); ++it) {
		delete it->second;
	}
}

Scope* Scope::open() {
	Scope* curr = new Scope();
	curr->prev = this;
	return curr;
}

Scope* Scope::close() {
	Scope *curr = this;
	Scope *ret = this->prev;
	delete curr;
	
	return ret;
}

void Scope::addSymbol(Token tok, Symbol* sym){
	if(table.count(tok))
		throw SymbolAlreadyInstalled(tok, *table[tok]);
	
	table[tok] = sym;
}

Symbol* Scope::find(Token tok) {
	for(Scope* scope = this; scope != NULL; scope = scope->prev) {
		if(scope->table.count(tok))
			return scope->table[tok];
	}

	throw SymbolNotFound(tok);
}