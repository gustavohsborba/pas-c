#ifndef _SCANNER_TEST_H
#define _SCANNER_TEST_H

#include <iostream>
#include <fstream>

#include "../frontend/Scanner.h"
#include "../test/Assertions.h"
#include "../test/TestCase.h"

using std::fstream;
using std::cout;
using std::endl;

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
	Token t;

	ASSERT_EQUALS(t = scan.nextToken(), TOK_VAR, cout << "Read " << t << endl ); 	// var
	ASSERT_EQUALS(t = scan.nextToken(), TOK_ID,  cout << "Read " << t << endl); 	// a
	ASSERT_EQUALS(t = scan.nextToken(), TOK_COMMA, cout << "Read " << t << endl);	// ,
	ASSERT_EQUALS(t = scan.nextToken(), TOK_ID, cout << "Read " << t << endl);	// b
	ASSERT_EQUALS(t = scan.nextToken(), TOK_COMMA, cout << "Read " << t << endl);	// ,
	ASSERT_EQUALS(t = scan.nextToken(), TOK_ID, cout << "Read " << t << endl); 	// c
	ASSERT_EQUALS(t = scan.nextToken(), TOK_IS, cout << "Read " << t << endl);	// is
	ASSERT_EQUALS(t = scan.nextToken(), TOK_INT, cout << "Read " << t << endl); // int
	ASSERT_EQUALS(t = scan.nextToken(), TOK_SEMICOLON, cout << "Read " << t << endl); // ;
	ASSERT_EQUALS(t = scan.nextToken(), TOK_ID, cout << "Read " << t << endl); // result
	ASSERT_EQUALS(t = scan.nextToken(), TOK_IS, cout << "Read " << t << endl); // is
	ASSERT_EQUALS(t = scan.nextToken(), TOK_INT, cout << "Read " << t << endl); // int
	ASSERT_EQUALS(t = scan.nextToken(), TOK_BEGIN, cout << "Read " << t << endl);
END_TEST()

#endif