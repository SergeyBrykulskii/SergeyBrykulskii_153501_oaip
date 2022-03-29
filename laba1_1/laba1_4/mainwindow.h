#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "ui_mainwindow.h"
#include "computerParts.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();
    void Sort();
private slots:

    void on_OpenFile_clicked();


    void on_Exit_clicked();

    void on_Add_clicked();

    void on_ShowInfo_clicked();

    void on_Search_clicked();

    void on_Sort_clicked();
    
    void on_comboBoxFirm_activated(int index);
    
    void on_comboBoxType_activated(int index);

    void on_radioButtonStock_clicked(bool checked);

    void on_radioButtonNStock_clicked(bool checked);
    
    void on_Equipment_clicked();
    
    void on_Delete_clicked();

private:
    Ui::MainWindowClass ui;
    ComputerParts* itemOfCP;
    int sizeOfArr, numOfCP;
    QString DFilePath, FilePath, firm, type, model;
    bool isInStock;
    double price, lowPrice, topPrice;

};
