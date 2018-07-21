
//stack.h
#include "position.h"
#include "board.h"

#ifndef stack_H
#define	stack_H

class stack
{
	private:
		board *stacka[65];
		int top;

	public:
		stack();
		~stack();
		board *pop();
		void push(board *input);
		int isempty();
		void freestack();

};


#endif