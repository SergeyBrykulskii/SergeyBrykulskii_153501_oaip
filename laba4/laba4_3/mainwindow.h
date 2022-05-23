#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

    std::string powstr(const std::string& str, const int& k);
    bool k_bit(std::string str, const int& k);
    void func();
	
public slots:
	void on_pushButton_clicked();
private:
    Ui::MainWindowClass ui;
};
