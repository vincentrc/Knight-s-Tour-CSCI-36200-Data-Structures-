
//position.h
#ifndef position_H
#define position_H

//This is just a class used to store a board location easily
class position
{
	private:
		int xcoord;
		int ycoord;
		int count; //keeps track of how many movement options have been tried in findpath function

	public:
		position();		
		~position();

		//Getters
		int getxcoord();
		int getycoord();
		int getcount();

		//Setters
		void setxcoord(int input);
		void setycoord(int input);
		void setcount(int input);

};

#endif