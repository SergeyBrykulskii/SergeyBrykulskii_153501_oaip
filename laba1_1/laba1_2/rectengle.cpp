#include "rectengle.h"

Rectengle::Rectengle(int len, int wid, int x1, int y1) : Shape()
{
    this->x1 = x1; this->y1 = y1; 
    this->len = len; this->wid = wid;
}
QRectF Rectengle::boundingRect() const
{
    return QRectF(0, 0, 500, 300);
}

void Rectengle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon rect;

    rect << QPoint(x1, y1) << QPoint(x1 + len, y1) << QPoint(x1 + len, y1 + wid) << QPoint(x1, y1 + wid);
    
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawPoint(x1 + len / 2, y1 + wid / 2);
    painter->drawPolygon(rect);
    //painter->translate(-30, -30);
}

double Rectengle::returnPerimeter()
{
    return (len + wid) * 2;
}

double Rectengle::returnSquare()
{
    return len * wid;
}
