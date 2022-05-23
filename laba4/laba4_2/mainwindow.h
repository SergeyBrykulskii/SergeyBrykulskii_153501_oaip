#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QMessageBox>
                                                                                                                                                                                           using std::string;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
	void on_pushButton_clicked();
	
private:
    string str1_, str2_;
    Ui::MainWindowClass ui;
};
