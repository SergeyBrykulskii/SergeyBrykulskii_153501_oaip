#include "Position.h"

Position::Position(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}

int Position::getPosX()
{
	return posX;
}

int Position::getPosY()
{
	return posY;
}

Position& Position::operator=(Position other)
{
	posX = other.getPosX();
	posY = other.getPosY();
	return *this;
}
