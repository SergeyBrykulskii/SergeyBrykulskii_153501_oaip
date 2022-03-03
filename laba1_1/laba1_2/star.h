#pragma once
#include "shape.h"
class Star :
    public Shape
{
public:
    Star(int num = 5, int x1 = 150, int y1 = 130, int radius = 100);
    double returnPerimeter();
    double returnSquare();
protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    int x, y, radius, num;
    double square;
};

