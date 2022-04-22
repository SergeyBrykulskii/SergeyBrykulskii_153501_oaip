#pragma once

#include "QString"
#include "QTime"

class Bus
{
private:
	int number;
	QString type, destination;
	QTime  ArrivalTime, DepartureTime;
	QTime QStringToQDate(QString str);
public:
	Bus(int number = 0, QString type = "", QString destination = "", QString ArrivalTime = "", QString DepartureTime = "");
	~Bus();
	
	int getNumber();
	QString getType();
	QString getDestination();
	QTime getArrivalTime();
	QTime getDepartureTime();

	bool operator>(const Bus& other) const;
	bool operator<(const Bus& other) const;
};

