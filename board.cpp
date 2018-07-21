
//board.cpp
#include "board.h"

board::board()
{
	int boarda[8][8] = {{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1, },
						{-1, -1, -1, -1, -1, -1, -1, -1 }};

	this->num = 0;
}

board::~board()
{
}


//Getters
int board::getcurxcoord()
{
	return this->curxcoord;
}

int board::getcurycoord()
{
	return this->curycoord;
}

int board::getnum()
{
	return this->num;
}

int board::getmovemade()
{
	return this->movemade;
}


//Setters
void board::setcurxcoord(int input)
{
	this->curxcoord = input;
}

void board::setcurycoord(int input)
{
	this->curycoord = input;
}

void board::setnum(int input)
{
	this->num = input;
}

void board::setmovemade(int input)
{
	this->movemade = input;
}