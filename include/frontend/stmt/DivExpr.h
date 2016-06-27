#ifndef _DIV_EXPR_H
#define _DIV_EXPR_H

#include "exception/InvalidOperation.h"
#include "exception/TypeMismatch.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"
#include "frontend/Type.h"

/**
 * Generate code to int product. 
 */
class DivExpr : public Expression {

public:
	DivExpr(CodeGenerator* gen, Expression *left, Expression *right) : Expression(gen), left(left), right(right) {
		if (left->getType() != right->getType() && left->getType() != NATIVE_INT) {
			throw TypeMismatch();
		} else if (left->getType() == NATIVE_STR) {
			throw InvalidOperation();
		}

		this->type = left->getType();
	}

	void emmit();

	~DivExpr() {
		delete left;
		delete right;
	}

private:
	Expression *left, *right;
};

#endif