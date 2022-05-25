#pragma once

#include <QtWidgets/QMainWindow>
#include "Map.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Map<int, QString> map;
	
    Ui::MainWindowClass ui;
};
