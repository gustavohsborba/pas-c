#ifndef _SYMBOL_H
#define _SYMBOL_H

typedef enum SymbolType {
	INT_TYPE,
	STRING_TYPE

}SymbolType;

class Symbol {
public:
	Symbol() {
	}

	virtual ~Symbol() {}

private:
	long address;

};
#endif