#include "rect.h"

Rect::Rect() {}

Rect::Rect(int pX, int pY, int ln, int wd) : QGraphicsRectItem(0)
{
    posX = pX;
    posY = pY;
    len = ln;
    wid = wd;

    QColor color1(0, 128, 0), color2(0, 100, 0);
    setBrush(color1);
    setRect(0, 0, ln, wd);

    QPen pen(color2);
    setPen(pen);
    setPos(pX, pY);
}

void Rect::advance(int phase)
{
    if (phase) {

        moveBy(moveSpeed, 0);

        if (this->x() == this->posX + 500 || this->x() == this->posX - 10)
        {
            this->getMovespeed() *= -1;
        }
    }
}

int& Rect::getMovespeed() {
    return moveSpeed;
}

Soldier::Soldier()
{
    body = new Rect(100, 210, 50, 140);
    leg1 = new Rect(100, 350, 22, 90);
    leg2 = new Rect(128, 350, 22, 90);
    arm = new Rect(150, 210, 22, 100);
}

Soldier::~Soldier()
{
    delete body;
    delete leg1;
    delete leg2;
    delete arm;
}

Rect* Soldier::ShowBody()
{
    return body;
}

Rect* Soldier::ShowLeg1()
{
    return leg1;
}

Rect* Soldier::ShowLeg2()
{
    return leg2;
}

Rect* Soldier::ShowArm()
{
    return arm;
}

Head::Head(int pX, int pY, int ln, int wd)
{
    posX = pX;
    posY = pY;
    len = ln;
    wid = wd;

    QColor color(240, 230, 140);
    setBrush(color);

    setRect(0, 0, ln, wd); 
    setPos(pX, pY);
}

Head::Head()
{}

int& Head::getMovespeed() {
    return moveSpeed;
}

void Head::advance(int phase)
{
    if (phase) {

        moveBy(moveSpeed, 0);

        if (this->x() == this->posX + 500 || this->x() == this->posX - 10)
        {
            this->getMovespeed() *= -1;
        }
    }
}

