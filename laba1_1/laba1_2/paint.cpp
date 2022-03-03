#include "paint.h"

Paint::Paint(QObject* parent) : QGraphicsScene(parent)
{}

void Paint::mousePressEvent(QGraphicsSceneMouseEvent* ev)
{
	addEllipse(ev->scenePos().x(), ev->scenePos().y(), 5, 5, QPen(Qt::NoPen), QBrush(Qt::red));
	{
		prevP = ev->scenePos();
	}
}

void Paint::mouseMoveEvent(QGraphicsSceneMouseEvent* ev)
{
	addLine(prevP.x(), prevP.y(), ev->scenePos().x(), ev->scenePos().y(), QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap));
	prevP = ev->scenePos();
}