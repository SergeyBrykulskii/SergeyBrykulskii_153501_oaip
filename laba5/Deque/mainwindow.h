#pragma once

#include <QtWidgets/QMainWindow>
#include "Deque.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
    void on_push_back_clicked();
    void on_push_front_clicked();
    void on_pop_back_clicked();
	void on_pop_front_clicked();
    void on_getElem_clicked();
    void on_clear_clicked();
	void on_Size_clicked();
	void on_Empty_clicked();
	
private:
    deque<int> dq;
	
    Ui::MainWindowClass ui;
};
