#include "mainwidow.h"

MainWidow::MainWidow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.tableWidget->setColumnWidth(50,100);
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->setColumnCount(4);
    QStringList headers;
    headers.append("Flight number");
    headers.append("Aircraft type");
    headers.append("Arrival airport");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);
}

QString MainWidow::ItoQStr(int num)
{
    QString str;
    str.setNum(num);
    return str;
}

void MainWidow::Show()
{
    ui.tableWidget->clear();
    int num = ui.tableWidget->rowCount();
	for(int i = 0; i < num; i++)
        ui.tableWidget->removeRow(0);
    QStringList headers;
    headers.append("Flight number");
    headers.append("Aircraft type");
    headers.append("Arrival airport");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);
	
    for (int i = 0; i < flights.GetCount(); i++)
    {       
        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(flights[i].getFlightNumber())));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(flights[i].getAircraftType()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(flights[i].getArrivalAirport()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(flights[i].getDepartureTime().toString()));
    }
}

void MainWidow::on_File_clicked()
{
    flights.Clear();
	
    FilePath = QFileDialog::getOpenFileName(this, "Choose file", "C:/", "(*.txt);");

    QFile file(FilePath);

    file.open(QFile::ReadOnly);

    QTextStream fin(&file);

    while (true)
    {
        number = fin.readLine();
		
        if (number.isEmpty())
        {
			break;
        }
        if (!isNumber(number) || number.size() > 10)
        {
            QMessageBox::critical(this, "Warning", "Please, choose correct file");
            flights.Clear();
            return;
        }
		
        aircraftType = fin.readLine();
        arrivalAirport = fin.readLine();

        departureTime = fin.readLine();

        QRegularExpression expr("^[0-1]?[0-9]:[0-5]?[0-9]$");
        QRegularExpression expr2("^2[0-3]:[0-5]?[0-9]$");
        QRegularExpressionMatch match = expr.match(departureTime);
        QRegularExpressionMatch match2 = expr2.match(departureTime);

        if (!match.hasMatch() && !match2.hasMatch())
        {
            QMessageBox::critical(this, "Warning", "Please, choose correct file");
            flights.Clear();
            return;
        }
        
        Flight* temp = new Flight(number.toInt(), aircraftType, arrivalAirport, departureTime);
        flights.push_back(temp);
    }


	Show();
}

bool MainWidow::isNumber(QString str)
{
    QString::const_iterator it = str.begin();
    while (it != str.end() && (*it).isDigit()) ++it;
    return !str.isEmpty() && it == str.end();
}

void MainWidow::qsort(DoubleList<Flight>& flights, int left, int right)
{
	int i = left, j = right;
	Flight x = flights[(left + right) / 2];
	do
	{
		while (flights[i] < x) i++;
		while (flights[j] > x) j--;
		if (i <= j)
		{
			Flight temp = flights[i];
			flights[i] = flights[j];
			flights[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) qsort(flights, left, j);
	if (i < right) qsort(flights, i, right);
}

void MainWidow::on_Show_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}

	if (flights.GetCount() == 0)
	{
		QMessageBox::critical(this, "Warning", "List is empty");
		return;
	}

	Show();
}

void MainWidow::on_Sort_clicked()
{
	if (flights.GetCount() == 0)
	{
		QMessageBox::critical(this, "Warning", "List is empty");
		return;
	}

    qsort(flights, 0, flights.GetCount() - 1);
    
    Show();
}

void MainWidow::on_comboBox_activated(int index)
{
    switch (index) {
    case 0: aircraftType = "Airbus";
        break;
    case 1: aircraftType = "Boeing";
        break;
    case 2: aircraftType = "Superjet";
		break;
    case 3: aircraftType = "Tupolev";
    }
}

void MainWidow::on_Add_clicked()
{
    if (FilePath.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, choose file");
        return;
    }
	
	number = ui.lineEditNumber->text();
    if (!isNumber(number) || number.size() > 10)
    {
        QMessageBox::critical(this, "Warning", "Please, enter correct Flight number");
		number = "";
        return;
    }
	
    if (aircraftType.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, enter Aircraft type");
        return;
    }
	
	arrivalAirport = ui.lineEditAirport->text();
	if (arrivalAirport.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, enter Arrival airport");
		arrivalAirport = "";
		return;
	}
	
	departureTime = ui.lineEditTime->text();
	QRegularExpression expr("^[0-1]?[0-9]:[0-5]?[0-9]$");
	QRegularExpression expr2("^2[0-3]:[0-5]?[0-9]$");

    QRegularExpressionMatch match = expr.match(departureTime);
    QRegularExpressionMatch match2 = expr2.match(departureTime);

    if (!match.hasMatch() && !match2.hasMatch())
    {
        QMessageBox::critical(this, "Warning", "Please, enter correct Departure time");
        departureTime = "";
        return;
    }
	
	Flight* temp = new Flight(number.toInt(), aircraftType, arrivalAirport, departureTime);
	
	flights.push_back(temp);
	
    ui.lineEditNumber->clear();
	ui.lineEditAirport->clear();
	ui.lineEditTime->clear();
	ui.comboBox->setCurrentIndex(0);
	
	QFile file(FilePath);

	file.open(QFile::Append);

	QTextStream fout(&file);

	fout << number << "\n" << aircraftType << "\n" << arrivalAirport << "\n" << departureTime << "\n";

	file.close();
	
	Show();
}

void MainWidow::on_Delete_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}
	
    arrivalAirport = ui.lineEditAirport->text();
    if (arrivalAirport.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, enter Arrival airport");
        arrivalAirport = "";
        return;
    }
	
	for (int i = 0; i < flights.GetCount(); i++)
	{
		if (flights[i].getArrivalAirport() == arrivalAirport)
		{
			flights.Remove(&flights[i]);
			break;
		}
	}
	
    ui.lineEditAirport->clear();
	
	Show();
}

void MainWidow::on_SearchByTime_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}
	
	QString time = ui.lineEditTime->text();
	QRegularExpression expr("^[0-1]?[0-9]:[0-5]?[0-9]$");
	QRegularExpression expr2("^2[0-3]:[0-5]?[0-9]$");

	QRegularExpressionMatch match = expr.match(time);
	QRegularExpressionMatch match2 = expr2.match(time);

	if (!match.hasMatch() && !match2.hasMatch())
	{
		QMessageBox::critical(this, "Warning", "Please, enter correct Departure time");
		time = "";
		return;
	}
	
	time += ":00";
	
    ui.tableWidget->clear();
    int num = ui.tableWidget->rowCount();
    for (int i = 0; i < num; i++)
        ui.tableWidget->removeRow(0);
    QStringList headers;
    headers.append("Flight number");
    headers.append("Aircraft type");
    headers.append("Arrival airport");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);
	
	for (int i = 0; i < flights.GetCount(); i++)
	{
		if (flights[i].getDepartureTime().toString() == time)
		{
            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(flights[i].getFlightNumber())));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(flights[i].getAircraftType()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(flights[i].getArrivalAirport()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(flights[i].getDepartureTime().toString()));
		}
	}
}

void MainWidow::on_SearchByAirport_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}
	
	QString airport = ui.lineEditAirport->text();
	if (airport.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, enter Arrival airport");
		airport = "";
		return;
	}
	
	ui.tableWidget->clear();
	int num = ui.tableWidget->rowCount();
	for (int i = 0; i < num; i++)
		ui.tableWidget->removeRow(0);
	QStringList headers;
	headers.append("Flight number");
	headers.append("Aircraft type");
	headers.append("Arrival airport");
	headers.append("Departure time");

	ui.tableWidget->setHorizontalHeaderLabels(headers);
	
	for (int i = 0; i < flights.GetCount(); i++)
	{
		if (flights[i].getArrivalAirport() == airport)
		{
			ui.tableWidget->insertRow(ui.tableWidget->rowCount());
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(flights[i].getFlightNumber())));
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(flights[i].getAircraftType()));
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(flights[i].getArrivalAirport()));
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(flights[i].getDepartureTime().toString()));
		}
	}
}

void MainWidow::on_SearchByNumber_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}
	
	QString number = ui.lineEditNumber->text();
	if (number.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, enter Flight number");
		number = "";
		return;
	}
	
	ui.tableWidget->clear();
	int num = ui.tableWidget->rowCount();
	for (int i = 0; i < num; i++)
		ui.tableWidget->removeRow(0);
	QStringList headers;
	headers.append("Flight number");
	headers.append("Aircraft type");
	headers.append("Arrival airport");
	headers.append("Departure time");

	ui.tableWidget->setHorizontalHeaderLabels(headers);
	
	for (int i = 0; i < flights.GetCount(); i++)
	{
		if (flights[i].getFlightNumber() == number.toInt())
		{
			ui.tableWidget->insertRow(ui.tableWidget->rowCount());
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(flights[i].getFlightNumber())));
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(flights[i].getAircraftType()));
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(flights[i].getArrivalAirport()));
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(flights[i].getDepartureTime().toString()));
		}
	}
}
