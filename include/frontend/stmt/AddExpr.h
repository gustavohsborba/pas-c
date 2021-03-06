#ifndef _ADD_EXPR_H
#define _ADD_EXPR_H

#include "exception/TypeMismatch.h"
#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

/**
 * \brief It represent both int addition and string concatenation. The only semantic check
 * is if the left and right sides of expression are of the same type.
 */
class AddExpr : public Expression {

public:

	AddExpr(CodeGenerator* gen, Expression *left, Expression *right) : Expression(gen), left(left), right(right) {
		
		if (left->getType() != right->getType()) {
			throw TypeMismatch();
		}

		this->type = left->getType();
	}

	void emmit();

	~AddExpr() {
		delete left;
		delete right;
	}

private:
	Expression * left, *right;
};

#endif