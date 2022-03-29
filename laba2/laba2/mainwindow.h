#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "unique_ptr.h"
#include "myStack.h"
#include "shared_ptr.h"
#include "weak_ptr.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_push_clicked();
    void on_pop_clicked();
private:
    Unique_ptr<MyStack<int>> stack = Unique_ptr<MyStack<int>>(new MyStack<int>(30));
    Ui::MainWindowClass ui;
};
