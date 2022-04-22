#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "doubleList.h"
#include "flight.h"
#include "ui_mainwidow.h"

class MainWidow : public QMainWindow
{
    Q_OBJECT

public:
    MainWidow(QWidget *parent = Q_NULLPTR);
public slots:
    void on_File_clicked();
    void on_Show_clicked();
    void on_Sort_clicked();
    void on_Add_clicked();
    void on_Delete_clicked(); 
    void on_SearchByTime_clicked();
    void on_SearchByAirport_clicked();
    void on_SearchByNumber_clicked();
	
    void on_comboBox_activated(int index);
	
private:
	DoubleList<Flight> flights;
    QString FilePath, aircraftType, arrivalAirport, departureTime, number;
    
    void qsort(DoubleList<Flight>& flights, int left, int right);
    QString ItoQStr(int num);
    void Show();
    bool isNumber(QString str);
    Ui::MainWidowClass ui;
};

