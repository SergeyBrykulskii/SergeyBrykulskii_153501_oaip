#include "flight.h"

Flight::Flight(int flightNumber, QString aircraftType, QString arrivalAirport, QString departureTime)
{
	this->flightNumber = flightNumber;
	this->aircraftType = aircraftType;
	this->arrivalAirport = arrivalAirport;
	this->departureTime = QStringToQDate(departureTime);
}

QTime Flight::QStringToQDate(QString str)
{
	QStringList list = str.split(":");
	return QTime(list[0].toInt(), list[1].toInt());
}

int Flight::getFlightNumber()
{
	return flightNumber;
}

QTime Flight::getDepartureTime()
{
	return departureTime;
}

QString Flight::getAircraftType()
{
	return aircraftType;
}

QString Flight::getArrivalAirport()
{
	return arrivalAirport;
}

bool Flight::operator>(const Flight& other) const
{
	return this->departureTime > other.departureTime;
}

bool Flight::operator<(const Flight& other) const
{
	return this->departureTime < other.departureTime;
}