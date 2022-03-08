#pragma once
#include <QString>

class ComputerParts
{
public:
	ComputerParts(QString firm = "", QString type = "", QString model = "", double price = 0, bool isInStock = false);
	QString returnType();
	QString returnModel();
	QString returnFirm();
	QString returnPrice();
	QString returnIsInStock();

private:
	QString type, model, firm;
	double price;
	bool isInStock;
};

