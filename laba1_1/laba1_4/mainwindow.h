#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include "ui_mainwindow.h"
#include "computerParts.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:

    void on_OpenFile_clicked();

private:
    Ui::MainWindowClass ui;
    QString FilePath;
};
