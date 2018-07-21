
//board.h
#include "position.h"

#ifndef board_H
#define board_H

class board
{
	private:
		int curxcoord;		//Stores knight's current x coord
		int curycoord;		//Stores knight's current y coord
		int num;			//Stores number of paths tried for this position so far
		int movemade;

	public:
		board();
		~board();
		int boarda[8][8];	//Array that stores the board state
		
		int badmove[8];		//Used to mark off moves that have proven to lead to dead ends
		
		//Getters
		int getcurxcoord();
		int getcurycoord();
		int getnum();
		int getmovemade();

		//Setters
		void setcurxcoord(int input);
		void setcurycoord(int input);
		void setnum(int input);
		void setmovemade(int input);


};

#endif