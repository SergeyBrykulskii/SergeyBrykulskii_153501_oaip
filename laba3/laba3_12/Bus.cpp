#include "bus.h"

Bus::Bus(int number, QString type, QString destination, QString ArrivalTime, QString DepartureTime)
{
	this->number = number;
	this->type = type;
	this->destination = destination;
	this->ArrivalTime = QStringToQDate(ArrivalTime);
	this->DepartureTime = QStringToQDate(DepartureTime);
}

QTime Bus::QStringToQDate(QString str)
{
	QStringList list = str.split(":");
	return QTime(list[0].toInt(), list[1].toInt());
}

int Bus::getNumber()
{
	return number;
}

QString Bus::getType()
{
	return type;
}

QString Bus::getDestination()
{
	return destination;
}

QTime Bus::getArrivalTime()
{
	return ArrivalTime;
}

QTime Bus::getDepartureTime()
{
	return DepartureTime;
}

bool Bus::operator>(const Bus& other) const
{
	return this->number > other.number;
}

bool Bus::operator<(const Bus& other) const
{
	return this->number < other.number;
}

Bus::~Bus()
{
}