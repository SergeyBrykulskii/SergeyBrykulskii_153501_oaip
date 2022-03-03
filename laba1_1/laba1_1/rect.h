//#pragma once
//class Rect :
//    public QGraphicsRectItem
//{
//};

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

class Rect : public QGraphicsRectItem
{
public:
    Rect();
    Rect(int pX, int pY, int ln, int wd);

    void advance(int phase);
    int& getMovespeed();
private:
    int moveSpeed = 1, posX, posY, len, wid;
};

class Soldier : public Rect
{
public:
    Soldier();
    ~Soldier();
    Rect* ShowBody();
    Rect* ShowLeg1();
    Rect* ShowLeg2();
    Rect* ShowArm();

private:
    Rect* body, * leg1, * leg2, * arm;
};

class Head : public QGraphicsEllipseItem
{
public:
    Head();
    Head(int pX, int pY, int ln, int wd);

    void advance(int phase);
    int& getMovespeed();
private:
    int moveSpeed = 1, posX, posY, len, wid;
};