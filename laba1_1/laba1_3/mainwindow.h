#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QTextStream>

#include "date.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

    void makeTable();
private slots:

    void on_ChooseFile_clicked();

    void on_add_clicked();

    void on_ChangeData_clicked();
private:
    Ui::MainWindowClass ui;
    
    QString FilePath, Birthday;
};
