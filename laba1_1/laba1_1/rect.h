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

class Head : public QGraphicsEllipseItem
{
public:
    Head();
    Head(int pX, int pY, int ln, int wd);

    Head* DrawHead(int pX, int pY, int ln, int wd);
    void advance(int phase);
    int& getMovespeed();
private:
    int moveSpeed = 1, posX, posY, len, wid;
};

class Soldier : public Head
{
public:
    Soldier();
    ~Soldier();
    //void DrawHead();
    Rect* ShowBody();
    Rect* ShowLeg1();
    Rect* ShowLeg2();
    Rect* ShowArm();

private:
    Rect* body, * leg1, * leg2, * arm;
};
