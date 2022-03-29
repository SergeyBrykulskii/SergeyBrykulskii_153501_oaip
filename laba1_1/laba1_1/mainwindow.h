#pragma once

#include "rect.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushSoldier_clicked();

    void on_pushStop_clicked();

    void on_pushGo_clicked();

    void on_pushButton_clicked();

    

private:
  
    static bool flag/*, flag1*/;
    Ui::MainWindowClass ui;
    QGraphicsScene* scene;
    QTimer* moveTimer;
    Soldier* sol;
    Rect* movingArm1, * movingArm2;
};