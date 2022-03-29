#include "circle.h"

Circle::Circle(int radius, int x1, int y1) : Shape()
{
    this->x1 = x1; this->y1 = y1;
    this->radius = radius;
}

QRectF Circle::boundingRect() const
{
    return QRectF(-10000, -10000, 100000, 100000);
}

void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

   
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawPoint(x1, y1);
    painter->drawEllipse(QPoint(x1, y1), radius, radius);
    //painter->translate(-30, -30);
}

double Circle::returnPerimeter()
{
    return 2 * 3.14 * radius;
}

double Circle::returnSquare()
{
    return 3.14 * radius * radius;
}

