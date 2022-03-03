#pragma once
#include <QtWidgets/QWidget>
#include <QPainter>
#include <QGraphicsScene>

#include "paint.h"
#include "ui_canvas.h"

//namespace Ui {
//    class Canva;
//}
class Canva : public QMainWindow
{
    Q_OBJECT

public:
    Canva(QMainWindow*parent = nullptr);

//private slots:

private:
    Paint* scn;
    Ui::Canva ui;
};

