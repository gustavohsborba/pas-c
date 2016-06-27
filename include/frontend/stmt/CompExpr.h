#ifndef _COMP_EXPR_H
#define _COMP_EXPR_H

#include "exception/TypeMismatch.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"
#include "frontend/TokenType.h"

/**
 * \brief It represent both int addition and string concatenation. The only semantic check
 * is if the left and right sides of expression are of the same type.
 */
class CompExpr : public Expression {

public:
	CompExpr(CodeGenerator* gen, TokenType op,  Expression *left, Expression *right) : Expression(gen), op(op), left(left), right(right) {
		
		if (left->getType() != right->getType()) {
			throw TypeMismatch();
		}

		this->type = left->getType();
	}

	void emmit();

	~CompExpr() {
		delete left;
		delete right;
	}

private:
	TokenType op;
	Expression * left, *right;
};

#endif