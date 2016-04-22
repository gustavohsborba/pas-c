#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include <exception>

#define ASSERT_TRUE(x) if(x){ incPass(); } \
	else { incFail(); std::cerr << "[FAIL] True assertion failed in " << __FILE__ << ":" << __LINE__  << ": " << (#x) << std::endl; } 

#define ASSERT_FALSE(x) if(!x){ incPass(); } \
	else { incFail(); std::cerr << "[FAIL] False assertion failed in " << __FILE__ << ":" << __LINE__  << ": " << (#x) << std::endl; }

#define ASSERT_EQUALS(x,y) if((x) == (y)) { incPass(); } \
	else {incFail(); std::cerr << "[FAIL] " << (#x) << " is not " << (#y) << " in " << __FILE__ << ":" << __LINE__ << std::endl; }

#define SHOULD_FAIL(x,exception_t) try{  \
	(x); \
	incFail(); std::cerr << "[FAIL] " << #x << " should fail in "<< __FILE__ << ":" << __LINE__ << std::endl; } \
	catch (exception_t _ex_) { incPass(); }

#define SHOULD_PASS(x) try{ \
	(x); \
	incPass(); \
	} catch (std::exception& _ex_) {incFail(); std::cerr << "[FAIL] " << #x << " thrown " << _ex_.what() << " in " << __FILE__ << ":" << __LINE__ << endl; }

#endif