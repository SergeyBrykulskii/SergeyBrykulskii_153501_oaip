#pragma once
#include "shape.h"
class Rhombus :
    public Shape
{
public:
    Rhombus(int len = 100, int x1 = 100, int y1 = 100);
    double returnPerimeter();
    double returnSquare();
protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    int x1, y1, len;
};

