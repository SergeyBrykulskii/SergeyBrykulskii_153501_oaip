#include "hexagon.h"

Hexagon::Hexagon(int length, int x1, int y1) : Shape()
{
    this->x1 = x1; this->y1 = y1;
    this->length = length;
}
QRectF Hexagon::boundingRect() const
{
    return QRectF(-10000, -10000, 100000, 100000);
}

void Hexagon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon hexagon;

    hexagon << QPoint(x1, y1) << QPoint(x1 + length, y1) << QPoint(x1 + length * 3 / 2, y1 + length * 1.73/2) 
        << QPoint(x1 + length, y1 + length * 1.73) << QPoint(x1, y1 + length * 1.73) << QPoint(x1 - length / 2, y1 + length * 1.73 / 2);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawPoint(x1 + length / 2, y1 + length * 1.73 / 2);
    painter->drawPolygon(hexagon);
    //painter->translate(-30, -30);
}

double Hexagon::returnPerimeter()
{
    return length * 6;
}

double Hexagon::returnSquare()
{
    return length * length * 1.73 / 4;
}