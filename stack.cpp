
//stack.cpp
#include <iostream>
#include "stack.h"
#include "board.h"


stack::stack()
{
	this->top = -1;		//Initializes top to -1 to start as empty
}

stack::~stack()
{
	
}

//Checks if stack is empty
int stack::isempty()
{
	if(this->top <= -1)
		return 1;
	else
		return 0;
}

//Pops the top object off of the stack if not empty and moves top to next object
board *stack::pop()
{
	int temp;


		temp = this->top;
		this->top--;
		return this->stacka[temp];

}

//Pushes a given position onto the stack if not full
void stack::push(board *input)
{
	if(top >= 65)
	{
		std::cout << "The stack is full!!";
		return;
	}

	else
	{
		this->top++;
		this->stacka[top] = input;
	}

}

void stack::freestack()
{
	int x, tc1 = 0;
	board *ptr;

	while(this->top > -1)
	{
		ptr = this->stacka[top];
		tc1++;
		delete ptr;
		top--;
	}
}



