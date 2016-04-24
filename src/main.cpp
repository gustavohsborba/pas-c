#include <iostream>
#include <unistd.h>

#include "test/TestCase.h"
#include "test/ScannerTest.h"
#include "test/ScopeTest.h"

#include "frontend/Scanner.h"

int main(int argc, char** argv) {
	Scanner::init();

#ifdef RUN_TESTS
	TEST(Scanner)
	TEST(Scope)
#endif

	fstream code;
	code.open(argv[1]);
	Scanner scan(code);

	Token t;

	cout << "Opening file " << argv[1] << "..." << endl;
	while (t = scan.nextToken(), t.getType() != TOK_EOF ) {
		if (t.getType() == TOK_UNKNOWN )
			cout << "ERROR in line " << scan.getLineCount()+1
				 << ", column " << scan.getColumnCount()-t.getValue().size()+1
				 << ": Unknown ";
		cout << "Token found: " << t << endl;

		//sleep(1);
	}


	return 0;
}