#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "Vector.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
public slots:
	void on_pushBack_clicked();
	void on_popBack_clicked();
	void on_sort_clicked();
	void on_swap_clicked();
	void on_reverse_clicked();
	void on_insert_clicked();
	void on_reserve_clicked();
	void on_erase_clicked();
	void on_clear_clicked();
	
private:
	Vector<int> vec;
    Ui::MainWindowClass ui;
};
