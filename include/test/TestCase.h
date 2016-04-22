#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

using std::string;

class TestCase {
public:
	TestCase(bool verbose=false){
		this->verbose = verbose;
		passed = failed = 0;
	}

	virtual void test() = 0;

	void incPass();

	void incFail();

	string result();

private:
	int passed;
	int failed;
	bool verbose;
};

#define TEST(_CLASS_)  { _CLASS_##Test t; t.test(); }

#define INIT_TEST(_CLASS_) class _CLASS_##Test : public TestCase { \
	public: _CLASS_##Test() : TestCase() {} \
	void test() { std::cout << "Testing " << #_CLASS_ << "..." << std::endl << std::endl;

#define END_TEST()  std::cout << result() << std::endl; } };

#endif