#include <typeinfo>
#include <sstream>
#include <string>

#include "../include/test/TestCase.h"
using std::endl;
using std::string;
using std::stringstream;

void TestCase::incPass() {
	passed++;
}

void TestCase::incFail(){
	failed++;
}

string TestCase::result() {
	stringstream res;
	int total = passed + failed;

	res << "------------------------------------------------" << endl
		<< "Test results for " << typeid(*this).name() << ": " << endl
		<< "Passed assertions: " << passed << "/" << total << endl 
		<< "Failed assertions: " << failed << "/" << total << endl;

	return res.str();
}
