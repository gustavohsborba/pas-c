#ifndef _SCANNER_TEST_H
#define _SCANNER_TEST_H

#include <fstream>

#include "frontend/Scanner.h"
#include "test/Assertions.h"
#include "test/TestCase.h"

using std::fstream;

INIT_TEST(Scanner)
	fstream code;

	code.open("tests/test1.psc");

	Scanner scan(code);

	/*
	var
	 a, b, c is int;
	 result is int
	begin
	 in (a);
	 in (c);
	 b := 10;
	 result := (a * c)/(b + 5 - 345);
	 out(result);
	end
	 */

	ASSERT_EQUALS(scan.nextToken().getType(), TOK_VAR); 	// var
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_ID); 	// a
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_COMMA);	// ,
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_ID);	// b
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_COMMA);	// ,
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_ID); 	// c
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_IS);	// is
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_INT); // int
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_SEMICOLON); // ;
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_ID); // result
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_IS); // is
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_INT); // int
	ASSERT_EQUALS(scan.nextToken().getType(), TOK_INT);
END_TEST()

#endif