#ifndef _SYNTAX_TEST_H
#define _SYNTAX_TEST_H

#include <sstream>
#include <string>

#include "exception/SyntaxError.h"

#include "frontend/Scanner.h"
#include "frontend/Syntax.h"

#include "test/Assertions.h"
#include "test/TestCase.h"

using std::string;
using std::stringstream;
using std::endl;


INIT_TEST(Syntax)

		stringstream  prod("-10*(b + c)");
		SHOULD_PASS(Syntax(new Scanner(prod), NULL).findExpression(), cout << "identified -10*(b + c)" << endl);

        stringstream div("-10*b/c");
		SHOULD_PASS(Syntax(new Scanner(div), NULL).findExpression(), cout << "identified -10*b/c" << endl);

        stringstream equal("a = b*c - c + a");
        SHOULD_PASS(Syntax(new Scanner(equal), NULL).findExpression(), cout << "a = b*c - c + a" << endl);

        stringstream diff("a*10 / c - 4 and 2 <> x and not b");
        SHOULD_PASS(Syntax(new Scanner(diff), NULL).findExpression(), cout << "a*10 / c - 4 and 2 <> x and not b" << endl);

        stringstream par("((((a + b)*c)-10)");
        SHOULD_FAIL(Syntax(new Scanner(par), NULL).findExpression(), SyntaxError, cout << "(((A + B)*C)-10)) have extra parenthesis" << endl);

END_TEST()

#endif