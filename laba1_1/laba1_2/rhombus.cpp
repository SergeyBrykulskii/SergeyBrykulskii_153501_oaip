#include "rhombus.h"

Rhombus::Rhombus(int len, int x1, int y1) : Shape()
{
    this->x1 = x1; this->y1 = y1;
    this->len = len;
}
QRectF Rhombus::boundingRect() const
{
    return QRectF(-10000, -10000, 100000, 100000);
}

void Rhombus::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon square;

    square << QPoint(x1, y1) << QPoint(x1 + len * 1.73 / 2, y1 + len / 2) 
        << QPoint(x1 + len * 1.73, y1) << QPoint(x1 + len * 1.73 / 2, y1 - len / 2);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawPoint(x1 + len * 1.73 / 2, y1);
    painter->drawPolygon(square);
    //painter->translate(-30, -30);
}

double Rhombus::returnPerimeter()
{
    return len * 4;
}

double Rhombus::returnSquare()
{
    return len * len * 1.73 / 2;
}