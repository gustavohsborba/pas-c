#include <iostream>

#include "test/TestCase.h"
#include "test/ScannerTest.h"

#include "frontend/Scanner.h"

int main(int argc, char** argv) {
	Scanner::init();

#ifdef RUN_TESTS
	TEST(Scanner) 
#endif

	return 0;
}