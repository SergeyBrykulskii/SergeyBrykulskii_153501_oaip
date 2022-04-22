#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "bus.h"
#include "ListOnArray.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
    void on_File_clicked();
    void on_Add_clicked();
    void on_Left_clicked();
    void on_OnStation_clicked();
    void on_OnWay_clicked();
    void on_Entered_clicked();
    void on_SearchByDestination_clicked();
    void on_SearchByTime_clicked();
    void on_Sort_clicked();

    void on_Type_activated(int index);
	
    
private:
    QString FilePath, number, type, destination, arrival, departure;
    ListOnArray<Bus> buses, busesOn;
    QString ItoQStr(int num);
    void qsort(ListOnArray<Bus>& flights, int left, int right);

    bool isNumber(QString str);
    void Show();

    Ui::MainWindowClass ui;
};
