#ifndef _ADD_EXPR_H
#define _ADD_EXPR_H

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

class AddExpr : public Expression {

public:

	AddExpr(CodeGenerator* gen, Expression *left, Expression *right) : left(left), right(right) {
		Statement::Statement(gen);
		
		if (left->type != right->type) {
			throw "Erro de tipo porra!";
		}

		this->type = left->type;
	}

	~AddExpr() {
		delete left;
		delete right;
	}

	void emmit();
private:
	Expression * left, right;


};

#endif