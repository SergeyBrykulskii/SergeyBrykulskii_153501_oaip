#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "BTS.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    void AddWidget(QTreeWidgetItem* oof, Node<QString>* root);

public slots:
    void on_Add_clicked();
	void on_Delete_clicked();
	void on_Find_clicked();
    void on_Calculate_clicked();
private:
    AVLTree<QString> tree;
    Ui::MainWindowClass ui;
};
