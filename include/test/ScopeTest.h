#ifndef _SCOPE_TEST_H
#define _SCOPE_TEST_H

#include "exception/SymbolAlreadyInstalled.h"
#include "exception/SymbolNotFound.h"

#include "frontend/Scope.h"
#include "frontend/Symbol.h"
#include "frontend/Token.h"

#include "test/Assertions.h"
#include "test/TestCase.h"


INIT_TEST(Scope) 

	Scope * scope = new Scope();
	scope->addSymbol(Token(TOK_ID, "a"), new Symbol());
	scope = scope->open();

	ASSERT_TRUE(scope->find(Token(TOK_ID, "a")), cout << "symbol a found successfully" << endl)
	SHOULD_FAIL(scope->find(Token(TOK_ID, "b")), SymbolNotFound, cout << "symbol b does exist in scope tree yet" << endl)
	
	scope->addSymbol(Token(TOK_ID, "b"), new Symbol());

	ASSERT_TRUE(scope->find(Token(TOK_ID, "b")), cout << "now b exists" << endl)

	scope = scope->close();

	SHOULD_FAIL(scope->find(Token(TOK_ID, "b")), SymbolNotFound, cout << "b does not exist anymore" << endl)
	SHOULD_FAIL(scope->addSymbol(Token(TOK_ID, "a"), new Symbol()), SymbolAlreadyInstalled, cout << "it does not replace installed symbols" << endl)
	scope = scope->close();

	ASSERT_FALSE(scope, NULL)

END_TEST()

#endif