#include <iostream>
#include <unistd.h>

#include "../include/test/TestCase.h"
#include "../include/test/ScannerTest.h"

#include "../include/frontend/Scanner.h"

int main(int argc, char** argv) {
	Scanner::init();

	fstream code;
	code.open(argv[1]);
	Scanner scan(code);

	Token t;

	cout << "Opening file " << argv[1] << "..." << endl;
	while (t = scan.nextToken(), t.getType() != TOK_EOF ) {
		cout << "Token found: " << t << endl;
		//sleep(1);
	}



//#ifdef RUN_TESTS
//	TEST(Scanner)
//#endif

	return 0;
}