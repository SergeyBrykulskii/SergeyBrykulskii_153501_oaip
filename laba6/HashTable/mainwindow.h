#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "HashTable.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
    void on_MakeHashTable_clicked();
    void on_FindMax_clicked();
private:
    int flag = 0;
    HashTable<int, int> ht;
    Ui::MainWindowClass ui;
};
