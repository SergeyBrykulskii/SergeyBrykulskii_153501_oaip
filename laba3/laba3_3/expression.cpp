 #include "expression.h"

Operator::Operator(short priority, QChar symbol)
{
	this->priority = priority;
	this->symbol = symbol;
}

short Operator::getPriority()
{
	return priority;
}

QChar Operator::getSymbol()
{
	return symbol;
}

OperatorContainer::OperatorContainer()
{
	number = 0;
	AddOperator(Operator(1, '('));
	AddOperator(Operator(1, ')'));
	AddOperator(Operator(2, '+'));
	AddOperator(Operator(2, '-'));
	AddOperator(Operator(3, '*'));
	AddOperator(Operator(3, '/'));
	AddOperator(Operator(4, '^'));
}

void OperatorContainer::AddOperator(Operator op)
{
	operators[number++] = op;
}

Operator OperatorContainer::FindOperator(QChar symbol)
{
	for (int i = 0; i < number; i++)
	{
		if (operators[i].getSymbol() == symbol)
		{
			return operators[i];
		}
	}
	return Operator();
}

Expression::Expression(QString expression, QString AValue, QString BValue, QString CValue, QString DValue, QString EValue)
{
	stack = new Stack<QChar>;
	this->result = 0;
	this->expression = expression;
	this->AValue = AValue;
	this->BValue = BValue;
	this->CValue = CValue;
	this->DValue = DValue;
	this->EValue = EValue;
	this->convertToInfix();
	this->calculate();
}

QString Expression::getExpression()
{
	return expression;
}

double Expression::getValue(QChar ch)
{
	if (ch == 'a')
	{
		return AValue.toDouble();
	}
	else if (ch == 'b')
	{
		return BValue.toDouble();
	}
	else if (ch == 'c')
	{
		return CValue.toDouble();
	}
	else if (ch == 'd')
	{
		return DValue.toDouble();
	}
	else if (ch == 'e')
	{
		return EValue.toDouble();
	}
}
QString Expression::getAValue()
{
	return AValue;
}

QString Expression::getBValue()
{
	return BValue;
}

QString Expression::getCValue()
{
	return CValue;
}

QString Expression::getDValue()
{
	return DValue;
}

QString Expression::getEValue()
{
	return EValue;
}

QString Expression::getInfixExpression()
{
	return infixExpression;
}

double Expression::getResult()
{
	return result;
}
bool Expression::convertToInfix()
{
	for (int i = 0; i < expression.size(); i++)
	{
		QChar ch = expression[i];
		if (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e')
		{
			infixExpression += ch;
		}
		else if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{
			if (stack->isEmpty())
			{
				stack->push(ch);
			}
			else if (OpCont.FindOperator(stack->peek()).getPriority() < OpCont.FindOperator(ch).getPriority())
			{
				stack->push(ch);
			}
			else
			{
				while (!stack->isEmpty() && OpCont.FindOperator(stack->peek()).getPriority() >= OpCont.FindOperator(ch).getPriority())
				{
					infixExpression += stack->pop();
				}
				
				stack->push(ch);
			}
				
		}
		else if (ch == '(')
		{
			stack->push(ch);
		}
		else if (ch == ')')
		{
			while (!stack->isEmpty() && stack->peek() != '(')
			{
				infixExpression += stack->pop();
			}
			if (!stack->isEmpty())
			{
				stack->pop();
			}
			else
			{
				return 0;	
			}
		}
	}
	
	while (!stack->isEmpty())
	{
		infixExpression += stack->pop();
	}
	
	return true;
}

void Expression::calculate()
{
	Stack<double> st;
	QString s = infixExpression;
	double temp;
	bool flag = false;
	for (int i = 0; i < this->infixExpression.size(); i++)
	{
		if (infixExpression[i] == 'a' || infixExpression[i] == 'b' || infixExpression[i] == 'c' || infixExpression[i] == 'd' || infixExpression[i] == 'e')
		{
			st.push(getValue(infixExpression[i]));
		}
		else
		{
			temp = st.pop();

			if (infixExpression[i] == '-')
			{
				st.push(st.pop() - temp);
			}
			else if (infixExpression[i] == '+')
			{
				st.push(st.pop() + temp);
			}
			else if (infixExpression[i] == '*')
			{
				st.push(st.pop() * temp);
			}
			else if (infixExpression[i] == '/')
			{
				st.push(st.pop() / temp);
			}
			else if (infixExpression[i] == '^')
			{
				st.push(pow(st.pop(), temp));
			}
		}
	}
	if (!st.isEmpty())
	result = st.pop();
}