#pragma once

#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "Stack.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_File_clicked();
    void on_Checker_clicked();
private:
    QString FilePath;
    QMessageBox msgBox;

    Ui::MainWindowClass ui;
};
