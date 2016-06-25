#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include <map>
#include <string>

#include "../frontend/Token.h"

using std::istream;
using std::ifstream;
using std::map;
using std::string;

class Scanner {
public:

	Scanner(istream& in) {
		this->in = &in;
		lineCount = columnCount = 0;
	}

	~Scanner();

	static void init();

	Token nextToken();
	long getLineCount();
	long getColumnCount();

private:

	Token getNumerical();
	Token getOperator();
	Token getLiteral();

	/*
	e' necessa'rio uma vez que, assim que se abre um caracter delimitador de string
	espacos em brancos passam a ser caracteres significativos
	*/
	Token getString();

	char get();
	char peek();


	string fileName;
	istream *in;
	long lineCount;
	long columnCount;

	static map<string, Token> reservedWords;
};

#endif