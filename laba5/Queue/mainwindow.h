#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "queue.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
	void on_push_clicked();
	void on_pop_clicked();
private:
	
	Queue<int> queue;
    Ui::MainWindowClass ui;
};
