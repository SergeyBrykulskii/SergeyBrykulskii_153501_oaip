#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QBrush>
#include <QTimer>

class Shape : public QGraphicsItem
{
public:
	Shape();
	virtual double returnPerimeter() = 0;
	virtual double returnSquare() = 0;
};

