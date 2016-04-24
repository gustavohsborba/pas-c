#ifndef _SCOPE_TEST_H
#define _SCOPE_TEST_H

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

	ASSERT_TRUE(scope->find(Token(TOK_ID, "a")), NULL)
	SHOULD_FAIL(scope->find(Token(TOK_ID, "b")), SymbolNotFound, NULL)
	
	scope->addSymbol(Token(TOK_ID, "b"), new Symbol());

	ASSERT_TRUE(scope->find(Token(TOK_ID, "b")), NULL)

	scope = scope->close();

	SHOULD_FAIL(scope->find(Token(TOK_ID, "b")), SymbolNotFound, NULL)

	scope = scope->close();

	ASSERT_FALSE(scope, NULL)

END_TEST()

#endif