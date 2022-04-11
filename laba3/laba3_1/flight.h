#pragma once

#include <QString>
#include <QDateTime>

class Flight
{
private:
	int flightNumber;
	QDateTime departureTime;
	QString aircraftType;
	QString arrivalAirport;
	
public:
	Flight(int flightNumber = 0, QDateTime departureTime = QDateTime(), QString aircraftType = "", QString arrivalAirport = "");
	int getFlightNumber();
	QDateTime getDepartureTime();
	QString getAircraftType();
	QString getArrivalAirport();

};
	
Flight::Flight(int flightNumber, QDateTime departureTime, QString aircraftType, QString arrivalAirport)
{
	this->flightNumber = flightNumber;
	this->departureTime = departureTime;
	this->aircraftType = aircraftType;
	this->arrivalAirport = arrivalAirport;
}

int Flight::getFlightNumber()
{
	return flightNumber;
}

QDateTime Flight::getDepartureTime()
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

