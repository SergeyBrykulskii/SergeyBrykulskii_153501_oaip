#pragma once

#include <QtWidgets/QMainWindow>
#include "Bitset.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Bitset<32> bitset;
    Ui::MainWindowClass ui;
};
