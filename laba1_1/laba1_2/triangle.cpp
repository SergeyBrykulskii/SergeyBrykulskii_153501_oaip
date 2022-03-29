#include "triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape()
{
    this->x1 = x1; this->x2 = x2; this->x3 = x3;
    this->y1 = y1; this->y2 = y2; this->y3 = y3;
}

QRectF Triangle::boundingRect() const
{
    return QRectF(-10000, -10000, 100000, 100000);
}

void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon trian;

    trian << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4); 
    painter->setPen(pen);
    painter->drawPoint((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3);
    painter->drawPolygon(trian);
    painter->translate(-30, -30);
}

double Triangle::returnPerimeter()
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) +
        sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)) + 
        sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
}

double Triangle::returnSquare()
{
    return fabs(x1 * y2 - y1 * x2 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3) / 2;
}