#include "star.h"

Star::Star(int num, int x, int y, int radius) :  Shape()
{
    this->x = x; this->y = y;
    this->radius = radius; this->num = num;
}
QRectF Star::boundingRect() const
{
    return QRectF(0, 0, 500, 300);
}

void Star::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path(QPoint(x, y - radius));
    double x2, y2, x3, y3;
    
    for (int i = 1; i <= num; i++)
    {
        x2 = x + sin((i * 2 - 1) * 3.14 / num) * radius / 2;
        y2 = y - cos((i * 2 - 1) * 3.14 / num) * radius / 2;
        x3 = x + sin(i * 2 * 3.14 / num) * radius + 1;
        y3 = y - cos(i * 2 * 3.14 / num) * radius - 1;
       
        path.lineTo(x2, y2);
        path.lineTo(x3, y3);
    }

    //painter->translate(-100, -120);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawPoint(x, y);
    painter->drawPath(path);
}

double Star::returnPerimeter()
{
    return num * 2 * sqrt(pow((x + sin(3.14 / num) * radius / 2) - (x + sin(6.28 / num) * radius + 1), 2) 
        + pow((y - cos(3.14 / num) * radius / 2) - (y - cos(6.28 / num) * radius - 1), 2));
}

double Star::returnSquare()
{
    double x1 = x, y1 = y - radius, x2, y2, x3, y3;
    square = 0;
    for (int i = 1; i <= num; i++)
    {
        x2 = x + sin((i * 2 - 1) * 3.14 / num) * radius / 2;
        y2 = y - cos((i * 2 - 1) * 3.14 / num) * radius / 2;
        x3 = x + sin(i * 2 * 3.14 / num) * radius + 1;
        y3 = y - cos(i * 2 * 3.14 / num) * radius - 1;

        square += (x1 * y2);
        square -= (y1 * x2);

        square += (x2 * y3);
        square -= (y2 * x3);

        x1 = x3;
        y1 = y3;
    }
    
    return fabs(square) / 2;
}

