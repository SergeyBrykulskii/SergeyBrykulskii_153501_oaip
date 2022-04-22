#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "Stack.h"
#include "expression.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

	QString DtoQStr(double num);
public slots:
	
	void on_Add_clicked();

	void on_Calculate_clicked();
private:
	Expression testExp[25];
	int num;
    Ui::MainWindowClass ui;
};
