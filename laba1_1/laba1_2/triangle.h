#pragma once

#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(int x1 = 150, int y1 = 150, int x2 = 75, int y2 = 0, int x3 = 0, int y3 = 150);
    double returnPerimeter();
    double returnSquare();
    
protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    
private:
    int x1, x2, x3, y1, y2, y3;
    
};

