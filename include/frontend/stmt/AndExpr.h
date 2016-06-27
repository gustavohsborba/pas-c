#ifndef _AND_EXPR_H
#define _AND_EXPR_H

#include "exception/TypeMismatch.h"
#include "exception/InvalidOperation.h"
#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

/**
 * \brief It represents or expressions. The semantic check is if both sides are same type and they must be integers.
 */
class AndExpr : public Expression {

public:

	AndExpr(CodeGenerator* gen, Expression *left, Expression *right) : Expression(gen), left(left), right(right) {
		
		if (left->getType() != right->getType() && left->getType() == NATIVE_INT) {
			throw TypeMismatch();
		} else if(left->getType() == NATIVE_STR) {
			throw InvalidOperation();
		}

		this->type = left->getType();
	}

	void emmit();

	~AndExpr() {
		delete left;
		delete right;
	}

private:
	Expression * left, *right;
};

#endif