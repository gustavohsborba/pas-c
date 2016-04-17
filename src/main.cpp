#include <iostream>

#include "frontend/Scanner.h"

using namespace std;

int main(int argc, char** argv) {
	Scanner::init();

	Scanner scanner("tests/test1.psc");

	cout << (scanner.nextToken().getType() & TOK_BEGIN) << endl;
}