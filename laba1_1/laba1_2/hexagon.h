#pragma once
#include "shape.h"

class Hexagon :
    public Shape
{
public:
    Hexagon(int length = 50, int x1 = 60, int y1 = 30);
    double returnPerimeter();
    double returnSquare();

protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    int x1, y1, length;
};

