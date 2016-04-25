#include <iostream>
#include <fstream>
#include <unistd.h>

#include "test/TestCase.h"
#include "test/ScannerTest.h"
#include "test/ScopeTest.h"

#include "exception/MalformedIdentifier.h"
#include "exception/UnknownOperator.h"
#include "frontend/Scanner.h"


using std::cout;
using std::endl;
using std::fstream;

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
	do  {

		try {
			t = scan.nextToken();
			cout << "Token found: " << t << endl;

		} catch (MalformedIdentifier& ex) {
			cout << "ERROR in line " << scan.getLineCount()+1
				 << ", column " << scan.getColumnCount()-t.getValue().size()+1
				 << ": " << ex.what() << endl;		
		} catch(UnknownOperator& ex) {
			cout << "ERROR in line " << scan.getLineCount()+1
				 << ", column " << scan.getColumnCount()-t.getValue().size()+1
				 << ": " << ex.what() << endl;	
		}

		//sleep(1);
	} while(t.getType() != TOK_EOF );


	return 0;
}