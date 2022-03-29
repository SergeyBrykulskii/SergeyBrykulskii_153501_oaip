#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "doubList.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_push_clicked();
    void on_pop_clicked();

private:
    Ui::MainWindowClass ui;
    DoubList list;
};
