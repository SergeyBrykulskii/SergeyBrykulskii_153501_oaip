#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "Unordered_Map.h"
#include "ui_mainwindow.h"
#include <ctime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
	
public slots:
    void on_Add_clicked();
    void on_Remove_clicked();
    void on_Find_clicked();
private:
    Unordered_Map<int, int> umap;
	
    Ui::MainWindowClass ui;
};
