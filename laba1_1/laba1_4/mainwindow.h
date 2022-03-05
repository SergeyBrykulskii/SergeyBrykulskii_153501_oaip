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

private slots:

    void on_OpenFile_clicked();

    void on_Exit_clicked();

    void on_Add_clicked();

    void on_ShowInfo_clicked();

private:
    Ui::MainWindowClass ui;
    static int size;
    QString FilePath;
};
