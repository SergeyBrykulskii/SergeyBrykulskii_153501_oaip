#pragma once
#include <QString>

class ComputerParts
{
public:
	ComputerParts(double price = 0, bool isInStock = false, QString type = "", QString model = "", QString firm = "");
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

