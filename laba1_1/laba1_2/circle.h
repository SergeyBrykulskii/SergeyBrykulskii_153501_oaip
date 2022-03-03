#pragma once
#include "shape.h"
class Circle :
    public Shape
{
public:
    Circle(int radius = 50, int x1 = 100, int y1 = 100);
    double returnPerimeter();
    double returnSquare();

protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    int x1, y1, radius;
};