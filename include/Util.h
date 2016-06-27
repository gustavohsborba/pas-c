#ifndef _UTIL_H
#define _UTIL_H

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

int strToInt(const string& s) { 
	stringstream ss;

	ss << s;
	int ret;
	ss >> ret;

	return ret;
}

#endif