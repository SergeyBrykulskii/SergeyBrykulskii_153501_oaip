#include "computerParts.h"

ComputerParts::ComputerParts(double price, bool isInStockse, QString type, QString model, QString firm)
{
	this->type = type; this->model = type; this->firm = firm;
	this->price = price;
	this->isInStock = isInStockse;
}

QString ComputerParts::returnType()
{
	return type;
}

QString ComputerParts::returnModel()
{
	return model;
}

QString ComputerParts::returnFirm()
{
	return firm;
}

QString ComputerParts::returnPrice()
{
	int intPart = price;
	int floatPart = (price - intPart) * 100;
	return QString::number(intPart) + '.' + QString::number(floatPart);
}

QString ComputerParts::returnIsInStock()
{
	return isInStock ? "there's in stock" : "there's not in stock";
}