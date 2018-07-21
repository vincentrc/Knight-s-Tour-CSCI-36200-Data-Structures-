
//position.cpp
#include "position.h"

position::position()
{
	this->count = 0;
}

position::~position()
{

}


//Getters
int position::getxcoord()
{
	return this->xcoord;
}

int position::getycoord()
{
	return this->ycoord;
}

int position::getcount()
{
	return this->count;
}


//Setters
void position::setxcoord(int input)
{
	this->xcoord = input;
}

void position::setycoord(int input)
{
	this->ycoord = input;
}

void position::setcount(int input)
{
	this->count = input;
}