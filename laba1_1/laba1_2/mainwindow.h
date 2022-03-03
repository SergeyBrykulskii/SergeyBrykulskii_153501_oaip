#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QTimer>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QRegularExpression>
#include <QMessageBox>
#include <QPainter>

#include "canva.h"
#include "rectengle.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "hexagon.h"
#include "rhombus.h"
#include "star.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private slots:
    void on_Triangle_clicked();
    void drawTriangle();

    void on_Rectengle_clicked();
    void drawRectengle();

    void on_Hexagon_clicked();
    void drawHexagon();

    void on_Rhombus_clicked();
    void drawRhombus();

    void on_Circle_clicked();
    void drawCircle();

    void on_Square_clicked();
    void drawSquare();

    void on_Star_clicked();
    void drawStar();


    void on_pushLeft_pressed();
    void moveLeft();
    void on_pushLeft_released();

    void on_pushRight_pressed();
    void moveRight();
    void on_pushRight_released();

    void on_pushDown_pressed();
    void moveDown();
    void on_pushDown_released();
    
    void on_pushUp_pressed();
    void moveUp();
    void on_pushUp_released();

    void on_pushRotationL_pressed();
    void RotateL();
    void on_pushRotationL_released();

    void on_pushRotationR_pressed();
    void RotateR();
    void on_pushRotationR_released();

    void on_ZoomIn_pressed();
    void ZoomIn();
    void on_ZoomIn_released();

    void on_ZoomOut_pressed();
    void ZoomOut();
    void on_ZoomOut_released();

    void on_Canva_clicked();

private:
    QTimer** timer;
    Shape* form;
    QGraphicsScene* scene;
    Canva* canva;
    QDialog* TrianParameters, * HexagonParameters, * CircleParameters,
        * SquareParameters, * RhombusParameters, * StarParameters;

    QLabel* X1, * X2, * X3, * Y1, * Y2, * Y3;
    QLineEdit* getX1, * getX2, * getX3, * getY1, * getY2, * getY3;
    
    QDialog* RectParameters;
    QLabel* len, * wid;
    QLineEdit* getLen, * getWid;
     
    QPushButton* Enter;

    static int angl;

    Ui::MainWindowClass ui;
};
