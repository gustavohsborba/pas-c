#include <iostream>
#include <fstream>
#include <unistd.h>

#include "test/TestCase.h"
#include "test/ScannerTest.h"
#include "test/ScopeTest.h"
#include "test/SyntaxTest.h"

#include "exception/MalformedIdentifier.h"
#include "exception/UnknownOperator.h"
#include "exception/SyntaxError.h"
#include "frontend/Scanner.h"
#include "frontend/Syntax.h"


using std::cout;
using std::endl;
using std::fstream;

int main(int argc, char** argv) {
	Scanner::init();

#ifdef RUN_TESTS
	TEST(Scanner)
	TEST(Scope)
	TEST(Syntax)
#endif

	fstream code;
	code.open(argv[1]);
	Scanner scan(code);
	Syntax parser(&scan);

	Token t;

	cout << "Opening file " << argv[1] << "..." << endl;
	try {
		parser.analyse();

	} catch (MalformedIdentifier& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;		
	} catch(UnknownOperator& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;	
	}	catch (SyntaxError& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;
	}


	return 0;
}