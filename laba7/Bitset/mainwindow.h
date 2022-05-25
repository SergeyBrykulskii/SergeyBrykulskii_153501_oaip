#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "Bitset.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    
public slots:
    void on_Make_clicked();
    void on_All_clicked();
    void on_Any_clicked();
    void on_None_clicked();
    void on_Size_clicked();
	
    void on_Flip_clicked();
	void on_Set_clicked();
    void on_Reset_clicked();
    void on_Test_clicked();
private:
    Bitset<32> bitset;
    Ui::MainWindowClass ui;
};
