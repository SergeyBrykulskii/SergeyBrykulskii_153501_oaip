#pragma once
#include "shape.h"
class Square :
    public Shape
{
public:
    Square(int len = 100, int x1 = 0, int y1 = 0);
    double returnPerimeter();
    double returnSquare();
protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    int x1, y1, len;
};

