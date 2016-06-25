#ifndef _SYMBOL_H
#define _SYMBOL_H


using std::string;

#define bit(i) (1L<<i)
#define tok_no(i) ((long)log2(i))

typedef enum VarType {
    VAR_INT = bit(0),
    VAR_STR = bit(1)
};

const string VAR_TYPES [] = {
        "VAR_INT", "VAR_STR"
};


class Symbol {
public:
	Symbol() {
	}

	~Symbol() {}

private:
	string name;
	bool method;
    VarType type;
};

#endif