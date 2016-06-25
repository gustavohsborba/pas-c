#ifndef _SCANNER_TEST_H
#define _SCANNER_TEST_H

#include <iostream>
#include <sstream>

#include "../frontend/Scanner.h"
#include "../test/Assertions.h"
#include "../test/TestCase.h"

#include "exception/MalformedIdentifier.h"

using std::stringstream;
using std::cout;
using std::endl;

INIT_TEST(Scanner)
	stringstream s;

	s << "_aidentifierthatmustthrowaexceptionblablablablablabla" << endl;

	Scanner scan(s);

	SHOULD_FAIL(scan.nextToken(), MalformedIdentifier, cout << "nao identifica nada acima de quinze caracteres" << endl)
END_TEST()

#endif