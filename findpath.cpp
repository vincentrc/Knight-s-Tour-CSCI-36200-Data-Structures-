
//findpath.cpp
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "functions.h"
#include "position.h"
#include "stack.h"
#include "board.h"



//Main function for finding a path for the Knight that covers the whole board
void findpath(startpos *start, stack *mystack)
{
	position *currentpos, *temppos;	//Will be used to point to current position object
	int move=0, count = 0, deadendcheck = 0;
	int exitcount[8], islegal[8];							//Used to store number of exits each possible move has ( 
	board *currentboard, *prevb;
	int x, y, z,  flag=0, backflag = 0;
	int movesx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//Holds x values for all possible moves
	int movesy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };	//Same but y values

	temppos = new position;
	currentboard = new board;
	prevb = new board;
	

	//Sets up the board array to begin with since it can't be initialized in a class apparently
	for(x=0;x<8;x++)
	{
		for(y=0;y<8;y++)
		{
			currentboard->boarda[y][x] = -1;
		}
	}

	currentpos = new position;						//Creates an instance for the start position
	currentpos->setxcoord(start->getxcoord()-1);	//Adjusts for array starting at 0
	currentpos->setycoord(7-(start->getycoord()-1));	//Same


	//Loop for determining next spot until all are covered
	while(1)
	{
		//Skips first time and checks to make sure a new board is needed (not a backtrack)
		if((flag != 0) && (backflag == 0))
		{
			currentboard = new board;
			*currentboard =*prevb;

			//Resets currentboard's bad moves 
			for(x=0;x<8;x++)
			{
				currentboard->badmove[x] = 0;
			}
		}

		flag = 1;
		deadendcheck = 0; //resets

		//Update board
		currentboard->boarda[currentpos->getycoord()][currentpos->getxcoord()] = count;

		//This will be for the first half that uses Warnsdoff rule
		if(count < 32)
		{
			//Loop to check for moves viability and exit count
			for(x=0;x<8;x++)
			{
				//Sets up temporary object to test moves on without affecting current position
				*temppos = *currentpos;
				temppos->setxcoord(temppos->getxcoord() + movesx[x]);
				temppos->setycoord(temppos->getycoord() + movesy[x]);

				//Checks to make sure the move is valid
				if( (temppos->getxcoord() >= 0 && temppos->getxcoord() <= 7) && (temppos->getycoord() >= 0 && temppos->getycoord() <= 7) 
					&& (currentboard->boarda[temppos->getycoord()][temppos->getxcoord()] == -1) && (currentboard->badmove[x] != 1))
				{	
					deadendcheck = 1; //Sets to show not dead end
					exitcount[x] = howmanyexits(temppos->getxcoord(),temppos->getycoord(),currentboard->boarda);
				}
				else
				{
					exitcount[x] = 10; //Number 10 will signify that this move is invalid
				}
			}

			//If the current position is a deadend
			if(deadendcheck == 0)
			{
				//Deletes currentboard and pops previous in order to backtrack
				delete currentboard;
				currentboard = mystack->pop();
				currentpos->setxcoord(currentboard->getcurxcoord());
				currentpos->setycoord(currentboard->getcurycoord());
				currentboard->badmove[currentboard->getmovemade()] = 1;	//Sets this move in the array so it is not repeated if this board is popped
				backflag = 1;	//sets to show that this was a backtrack, so no new board is needed at top of the loop
				count--;
				continue;

			}
			//If not
			else
			{
				z = findlowest(exitcount);

				//Sets the position on the board and preps for pushing to stack
				currentboard->setcurxcoord(currentpos->getxcoord());
				currentboard->setcurycoord(currentpos->getycoord()); 
				currentboard->setmovemade(z);
				*prevb = *currentboard;

				mystack->push(currentboard);

				//Sets up new position
				updatecurrentpos(currentpos, z);
				backflag = 0;
				count++;

			}

		}



		//**************************************************************************
		//**************************************************************************
		//**************************************************************************
		//This section is for the second half where Warnsdoff rule is no longer used
		else if(count < 63)
		{
			//Loop to check for moves viability and exit count
			for(x=0;x<8;x++)
			{
				//Sets up temporary object to test moves on without affecting current position
				*temppos = *currentpos;
				temppos->setxcoord(temppos->getxcoord() + movesx[x]);
				temppos->setycoord(temppos->getycoord() + movesy[x]);

				//Checks to make sure the move is valid
				if( (temppos->getxcoord() >= 0 && temppos->getxcoord() <= 7) && (temppos->getycoord() >= 0 && temppos->getycoord() <= 7) 
					&& (currentboard->boarda[temppos->getycoord()][temppos->getxcoord()] == -1) && (currentboard->badmove[x] != 1))
				{	
					deadendcheck = 1; //Sets to show not dead end
					islegal[x] = 1; //Now used to 
				}
				else
				{
					islegal[x] = 0; //Number 0 will signify that this move is invalid
				}
			}

			//If the current position is a deadend
			if(deadendcheck == 0)
			{
				//Deletes currentboard and pops previous in order to backtrack
				delete currentboard;
				currentboard = mystack->pop();
				currentpos->setxcoord(currentboard->getcurxcoord());
				currentpos->setycoord(currentboard->getcurycoord());
				currentboard->badmove[currentboard->getmovemade()] = 1;	//Sets this move in the array so it is not repeated if this board is popped
				backflag = 1;	//sets to show that this was a backtrack, so no new board is needed at top of the loop
				count--;
				continue;

			}
			//If not
			else
			{
				//Simply chooses the first viable move to try next
				for(x=7;x>=0;x--)
				{
					if(islegal[x] == 1)
					{
						z = x;
						break;
					}
				}

				//Sets the position on the board and preps for pushing to stack
				currentboard->setcurxcoord(currentpos->getxcoord());
				currentboard->setcurycoord(currentpos->getycoord()); 
				currentboard->setmovemade(z);
				*prevb = *currentboard;

				mystack->push(currentboard);

				//Sets up new position
				updatecurrentpos(currentpos, z);
				backflag = 0;
				count++;

			}
		}
		
		//Breaks the loop once finished
		else
			break;
	}


	displayboard(currentboard);
	mystack->freestack();
	delete prevb;
	delete currentboard;
	delete currentpos;
	delete temppos;
}
