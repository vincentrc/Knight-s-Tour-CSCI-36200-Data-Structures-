
//starpos.cpp
#include "startpos.h"

startpos::startpos()
{

}

startpos::~startpos()
{

}


//Getters
int startpos::getxcoord()
{
	return startpos::xcoord;
}

int startpos::getycoord()
{
	return startpos::ycoord;
}

int startpos::getnum()
{
	return startpos::num;
}

startpos *startpos::getnextpos()
{
	return this->nextpos;
}


//Setters
void startpos::setxcoord(int input)
{
	startpos::xcoord = input;
}

void startpos::setycoord(int input)
{
	startpos::ycoord = input;
}

void startpos::setnum(int input)
{
	startpos::num = input;
}

void *startpos::setnextpos(startpos *input)
{
	startpos::nextpos = input;
	return 0;
}




