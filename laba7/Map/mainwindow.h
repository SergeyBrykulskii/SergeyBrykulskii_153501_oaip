#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "Map.h"
#include "Set.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
    void on_InsertMap_clicked();
    void on_FindMap_clicked();
    void on_RemoveMap_clicked();

	void on_InsertSet_clicked();
	void on_FindSet_clicked();
	void on_RemoveSet_clicked();
private:
    Map<int, QString> map;
    Set<int> set;
	
    Ui::MainWindowClass ui;
};
