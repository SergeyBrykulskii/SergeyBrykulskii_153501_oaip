#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.tableWidget->setColumnWidth(50, 100);
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->setColumnCount(5);
    QStringList headers;
    headers.append("Number of bus");
    headers.append("Type of bus");
    headers.append("Destination"); 
    headers.append("Arrival time");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);	

}

bool MainWindow::isNumber(QString str)
{
    QString::const_iterator it = str.begin();
    while (it != str.end() && (*it).isDigit()) ++it;
    return !str.isEmpty() && it == str.end();
}

QString MainWindow::ItoQStr(int num)
{
    QString str;
    str.setNum(num);
    return str;
}

QTime QStringToQDate(QString str)
{
    QStringList list = str.split(":");
    return QTime(list[0].toInt(), list[1].toInt());
}

void MainWindow::Show()
{
    ui.tableWidget->clear();
    int num = ui.tableWidget->rowCount();
    for (int i = 0; i < num; i++)
        ui.tableWidget->removeRow(0);
    QStringList headers;
    headers.append("Number of bus");
    headers.append("Type of bus");
    headers.append("Destination");
    headers.append("Arrival time");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < buses.GetCount(); i++)
    {
        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(buses[i].getNumber())));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(buses[i].getType()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(buses[i].getDestination()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(buses[i].getArrivalTime().toString()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(buses[i].getDepartureTime().toString()));
    }
}

void MainWindow::on_File_clicked()
{
    buses.Clear();
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
            buses.Clear();
            return;
        }

        type = fin.readLine();
        destination = fin.readLine();

        arrival = fin.readLine();

        QRegularExpression expr("^[0-1]?[0-9]:[0-6]?[0-9]$");
        QRegularExpression expr2("^2[0-3]:[0-5]?[0-9]$");
        QRegularExpressionMatch match = expr.match(arrival);
        QRegularExpressionMatch match2 = expr2.match(arrival);

        if (!match.hasMatch() && !match2.hasMatch())
        {
            QMessageBox::critical(this, "Warning", "Please, choose correct file");
            buses.Clear();
            return;
        }
		
        departure = fin.readLine();

        match = expr.match(departure);
        match2 = expr2.match(departure);

        if (!match.hasMatch() && !match2.hasMatch())
        {
            QMessageBox::critical(this, "Warning", "Please, choose correct file");
            buses.Clear();
            return;
        }

		arrival += ":00";
		departure += ":00";
		
        Bus* temp = new Bus(number.toInt(), type, destination, arrival, departure);
        buses.push_back(temp);
        
    }
    type = "";
    Show();
}

void MainWindow::on_Type_activated(int index)
{
    switch (index) {
    case 0: type = "Sleeper bus";
        break;
    case 1: type = "Party bus";
        break;
    case 2: type = "Cargo-passenger";
    }
}

void MainWindow::on_Add_clicked()
{
    if (FilePath.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, choose file");
        return;
    }

    number = ui.Number->text();
    if (!isNumber(number) || number.size() > 10)
    {
        QMessageBox::critical(this, "Warning", "Please, enter correct Number of bus");
        number = "";
        return;
    }

    if (type.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, enter Type of bus");
        return;
    }

    destination = ui.Destination->text();
    if (destination.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, enter Destination");
        destination = "";
        return;
    }

    departure = ui.Departure->text();
    QRegularExpression expr("^[0-1]?[0-9]:[0-6]?[0-9]$");
    QRegularExpression expr2("^2[0-3]:[0-5]?[0-9]$");

    QRegularExpressionMatch match = expr.match(departure);
    QRegularExpressionMatch match2 = expr2.match(departure);

    if (!match.hasMatch() && !match2.hasMatch())
    {
        QMessageBox::critical(this, "Warning", "Please, enter correct Departure time");
        departure = "";
        return;
    }
    
    arrival = ui.Arrival->text();
   

    match = expr.match(arrival);
    match2 = expr2.match(arrival);

    if (!match.hasMatch() && !match2.hasMatch())
    {
        QMessageBox::critical(this, "Warning", "Please, enter correct Arrival time");
        arrival = "";
        return;
    }

    Bus* temp = new Bus(number.toInt(), type, destination, arrival, departure);
    buses.push_back(temp);

    ui.Number->clear();
    ui.Destination->clear();
    ui.Departure->clear();
    ui.Arrival->clear();
    ui.Type->setCurrentIndex(0);

    QFile file(FilePath);

    file.open(QFile::Append);

    QTextStream fout(&file);

    fout << number << "\n" << type << "\n" << destination << "\n" << arrival << "\n" << departure << "\n";

    file.close();

    Show();
}


void MainWindow::on_SearchByDestination_clicked()
{
    if (FilePath.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, choose file");
        return;
    }

    QString destination = ui.Destination->text();
    if (destination.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, enter Destination");
        destination = "";
        return;
    }

    ui.tableWidget->clear();
    int num = ui.tableWidget->rowCount();
    for (int i = 0; i < num; i++)
        ui.tableWidget->removeRow(0);
    QStringList headers;
    headers.append("Number of bus");
    headers.append("Type of bus");
    headers.append("Destination");
    headers.append("Arrival time");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < buses.GetCount(); i++)
    {
        if (buses[i].getDestination() == destination)
        {
            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(buses[i].getNumber())));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(buses[i].getType()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(buses[i].getDestination()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(buses[i].getArrivalTime().toString()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(buses[i].getDepartureTime().toString()));
        }
    }
    ui.Destination->clear();
}

void MainWindow::on_SearchByTime_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}

	QString time = ui.Departure->text();
	if (time.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, enter Departure time");
		time = "";
		return;
	}

	QRegularExpression expr("^[0-1]?[0-9]:[0-6]?[0-9]$");
	QRegularExpression expr2("^2[0-3]:[0-5]?[0-9]$");
	QRegularExpressionMatch match = expr.match(time);
	QRegularExpressionMatch match2 = expr2.match(time);

	if (!match.hasMatch() && !match2.hasMatch())
	{
		QMessageBox::critical(this, "Warning", "Please, choose Departure time");
		return;
	}

	ui.tableWidget->clear();
	int num = ui.tableWidget->rowCount();
	for (int i = 0; i < num; i++)
		ui.tableWidget->removeRow(0);
	QStringList headers;
	headers.append("Number of bus");
	headers.append("Type of bus");
	headers.append("Destination");
	headers.append("Arrival time");
	headers.append("Departure time");

	ui.tableWidget->setHorizontalHeaderLabels(headers);
    time += ":00";
	QTime time1 = QStringToQDate(time);
    for (int i = 0; i < buses.GetCount(); i++)
    {
		QTime temp = buses[i].getDepartureTime();
        if (buses[i].getDepartureTime() <= time1)
        {
            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(buses[i].getNumber())));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(buses[i].getType()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(buses[i].getDestination()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(buses[i].getArrivalTime().toString()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(buses[i].getDepartureTime().toString()));
        }
    }
    ui.Departure->clear();
}

void MainWindow::on_Left_clicked()
{
    if (FilePath.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, choose file");
        return;
    }
	
    QString number = ui.Number->text();
    if (number.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please, enter Number of bus");
        number = "";
        return;
    }

    for (int i = 0; i < buses.GetCount(); i++)
    {
        if (buses[i].getNumber() == number.toInt())
        {
            Bus* temp = new Bus(buses[i].getNumber(), buses[i].getType(), buses[i].getDestination(), buses[i].getArrivalTime().toString(), buses[i].getDepartureTime().toString());
            busesOn.push_back(temp);
            buses.Remove(&buses[i]);
			break;
        }
    }
	
    ui.Number->clear();
	
    Show();
}

void MainWindow::on_Entered_clicked()
{
	if (FilePath.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, choose file");
		return;
	}

	QString number = ui.Number->text();
	if (number.isEmpty())
	{
		QMessageBox::critical(this, "Warning", "Please, enter Number of bus");
		number = "";
		return;
	}

	for (int i = 0; i < busesOn.GetCount(); i++)
	{
		if (busesOn[i].getNumber() == number.toInt())
		{
			Bus* temp = new Bus(busesOn[i].getNumber(), busesOn[i].getType(), busesOn[i].getDestination(), busesOn[i].getArrivalTime().toString(), busesOn[i].getDepartureTime().toString());
			buses.push_back(&busesOn[i]);
            busesOn.Remove(&busesOn[i]);

			break;
		}
	}

    ui.Number->clear();
	Show();
}

void MainWindow::on_OnStation_clicked()
{
    Show();
}

void MainWindow::on_OnWay_clicked()
{
    ui.tableWidget->clear();
    int num = ui.tableWidget->rowCount();
    for (int i = 0; i < num; i++)
        ui.tableWidget->removeRow(0);
    QStringList headers;
    headers.append("Number of bus");
    headers.append("Type of bus");
    headers.append("Destination");
    headers.append("Arrival time");
    headers.append("Departure time");

    ui.tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < busesOn.GetCount(); i++)
    {
        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ItoQStr(busesOn[i].getNumber())));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(busesOn[i].getType()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(busesOn[i].getDestination()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(busesOn[i].getArrivalTime().toString()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(busesOn[i].getDepartureTime().toString()));
    }
}

void MainWindow::qsort(ListOnArray<Bus>& flights, int left, int right)
{
    int i = left, j = right;
    Bus x = flights[(left + right) / 2];
    do
    {
        while (flights[i] < x) i++;
        while (flights[j] > x) j--;
        if (i <= j)
        {
            Bus temp = flights[i];
            flights[i] = flights[j];
            flights[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) qsort(flights, left, j);
    if (i < right) qsort(flights, i, right);
}

void MainWindow::on_Sort_clicked()
{
    if (buses.GetCount() == 0)
    {
        QMessageBox::critical(this, "Warning", "List is empty");
        return;
    }
    qsort(buses, 0, buses.GetCount() - 1);

    Show();
}