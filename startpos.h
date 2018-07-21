
//starpos.h
#ifndef startpos_H
#define startpos_H

class startpos
{
	public:

		startpos();		//Constructor
		~startpos();	//Destructor

		//Getters
		int getxcoord();
		int getycoord();
		int getnum();
		startpos *getnextpos();

		//Setters
		void setxcoord(int input);
		void setycoord(int input);
		void setnum(int input);
		void *setnextpos(startpos *input);


	private:
		
		//Attributes
		int xcoord;
		int ycoord;
		int num;
		startpos *nextpos;



};


#endif