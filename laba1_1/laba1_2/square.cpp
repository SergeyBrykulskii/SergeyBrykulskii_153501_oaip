#include "square.h"

Square::Square(int len, int x1, int y1) : Shape()
{
    this->x1 = x1; this->y1 = y1;
    this->len = len;
}
QRectF Square::boundingRect() const
{
    return QRectF(-10000, -100000, 100000, 100000);
}

void Square::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon square;

    square << QPoint(x1, y1) << QPoint(x1 + len, y1) << QPoint(x1 + len, y1 + len) << QPoint(x1, y1 + len);

    //painter->translate(-100, -100);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawPoint(x1 + len / 2, y1 + len / 2);
    painter->drawPolygon(square);
}

double Square::returnPerimeter()
{
    return len * 4;
}

double Square::returnSquare()
{
    return len * len;
}