#pragma once

#include <QString>
#include <QDateTime>

class Flight
{
private:
	int flightNumber;
	QTime departureTime;
	QString aircraftType;
	QString arrivalAirport;
	
	QTime QStringToQDate(QString str);
	
public:
	Flight(int flightNumber = 0, QString aircraftType = "", QString arrivalAirport = "", QString departureTime = "");
	int getFlightNumber();
	QTime getDepartureTime();
	QString getAircraftType();
	QString getArrivalAirport();
	
	bool operator>(const Flight& other) const;
	bool operator<(const Flight& other) const;
};

