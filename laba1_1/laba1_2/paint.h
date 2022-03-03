#pragma once
#include <QtWidgets/QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class Paint :
    public QGraphicsScene
{
public:
    Paint(QObject* perent = nullptr);

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent* ev);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* ev);

protected:
    QPointF prevP;
};

