#pragma once

#include <qstring.h>
#include "Stack.h"

class Operator
{
private:
	short priority;
	QChar symbol;
public:
	Operator(short priority = 0, QChar symbol = ' ');
	short getPriority();
	QChar getSymbol();
};

class OperatorContainer
{
private:
	Operator operators[8];
	int number;
public:
	OperatorContainer();
	void AddOperator(Operator op);
	Operator FindOperator(QChar symbol);
};

class Expression
{
private:
	Stack<QChar>* stack;
	QString expression, AValue, BValue, CValue, DValue, EValue, infixExpression;
	OperatorContainer OpCont = OperatorContainer();
	
public:
	Expression(QString expression = "", QString AValue = "0", QString BValue = "0", QString CValue = "0", QString DValue = "0", QString EValue = "0");
	QString getExpression();
	QString getAValue();
	QString getBValue();
	QString getCValue();
	QString getDValue();
	QString getEValue();
	QString getInfixExpression();
	
	bool convertToInfix();
	double calculate();
};
