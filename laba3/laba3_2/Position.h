#pragma once

class Position
{
private:
	int posX, posY;
public:
	Position() : posX(0), posY(0) {};
	Position(int posX, int posY);
	Position& operator=(Position other);
	int getPosX();
	int getPosY();
};

