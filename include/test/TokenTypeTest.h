//
// Created by felipe on 28/05/16.
//

#ifndef _TOKEN_TYPE_TEST_H
#define _TOKEN_TYPE_TEST_H

#include "frontend/TokenType.h"

#include "test/Assertions.h"
#include "test/TestCase.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::find;
using std::vector;

INIT_TEST(TokenType)
        long mask = TOK_ADD | TOK_AND | TOK_EOF;
        vector<TokenType> t = unmask(mask);

        ASSERT_TRUE(t.size() == 3, cout << "found three tokens in mask" << endl);
        ASSERT_TRUE(find(t.begin(), t.end(), TOK_ADD) != t.end(), cout << "found TOK_ADD in mask " << mask << endl);
        ASSERT_TRUE(find(t.begin(), t.end(), TOK_AND) != t.end(), cout << "found TOK_AND in mask " << mask << endl);
        ASSERT_TRUE(find(t.begin(), t.end(), TOK_EOF) != t.end(), cout << "found TOK_EOF in mask " << mask << endl);
        ASSERT_TRUE(find(t.begin(), t.end(), TOK_DIV) == t.end(), cout << "didn\'t found TOK_DIV in mask " << mask << endl);
        ASSERT_TRUE(find(t.begin(), t.end(), TOK_SUB) == t.end(), cout << "didn\'t found TOK_SUB in mask " << mask << endl);
        ASSERT_TRUE(find(t.begin(), t.end(), TOK_IS) == t.end(), cout << "didn\'t found TOK_IS in mask " << mask << endl);
        ASSERT_TRUE(unmask(0).empty(), cout << "Unmask of 0 return an empty list" << endl);

END_TEST()

#endif //_TOKEN_TYPE_TEST_H
