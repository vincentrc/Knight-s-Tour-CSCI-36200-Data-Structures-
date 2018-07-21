
//functions.cpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "startpos.h"
#include "position.h"
#include "board.h"

void *addpos(startpos *head, int x, int y)
{
	startpos *node;
	int count=1;

	node = head;
	

	//Finds the end of the list
	while(node->getnextpos() != NULL)
	{
		node = node->getnextpos();
		count++;
	}

	//Creates new node in list
	startpos *newnode = new startpos;

	//Fills new node with user input and spot on list
	newnode->setxcoord(x);
	newnode->setycoord(y);
	newnode->setnum(count);
	newnode->setnextpos(NULL);
	node->setnextpos(newnode);

	return 0;

}



void displaylist(startpos *head)
{
	startpos *node;
	std::ofstream tscript;

	tscript.open("transcript.txt", std::ofstream::app);



	if(head->getnextpos() == NULL)
	{
		std::cout << "\n\nThe list is empty!\n\n";
		tscript.close();
		return;
	}

	node = head->getnextpos();

	//Loop for displaying each node in list
	while(1)
	{
		printf( "%d:   %d,%d\n\n", node->getnum(), node->getxcoord(), node->getycoord());
		tscript << node->getnum() << ":   " << node->getxcoord() << "," <<  node->getycoord() << "\n\n";
		if(node->getnextpos() == NULL)
		{
			break;
		}

		else
		{
			node = node->getnextpos();
		}
	}

	tscript.close();
}



void addnode(startpos *head)
{
	std::string inpt;
	std::ofstream tscript;

	tscript.open("transcript.txt", std::ofstream::app);

	//Resets the screen to look neater
	std::cout << "\033[H\033[2J";

	std::cout << "Please enter the starting position as before:\n\n";
	tscript << "Please enter the starting position as before:\n\n";

	//Loop in case of incorrect entry
	while(1)
	{
		//Takes input
		std::getline(std::cin, inpt);

		tscript<< inpt + "\n\n";

		//Incorrect input handling
		if(inpt.length()<3 || (inpt[1] != ',') || (inpt[0]>'8'||inpt[0]<'1') || ((inpt[2]>'8'||inpt[2]<'1')) || inpt.length()>3)
		{
			std::cout << "\nInvalid input, please try again:\n\n";
			tscript << "\nInvalid input, please try again:\n\n";
			continue;
		}

		else
			break;
	}


	//Calls add funtion (-48 on inputs to adjust ascii value)
	addpos(head,inpt[0]-48,inpt[2]-48);

	tscript.close();
}



//Simply returns a pointer to the element of the list that matches the number passed if a match exists
startpos *searchbynum(startpos *head, double num)
{
	startpos *node;

	node = head->getnextpos();

	while(1)
	{
		if(num == node->getnum())
		{
			return node;
		}

		else if(node->getnextpos() == NULL)
		{
			std::cout << "\n\nNot Found!";
			return NULL;
		}

		else
		{
			node = node->getnextpos();
		}
			
	}

}



void removenode(startpos *head)
{
	startpos *node1, *node2;
	std::string entry;
	double entrydoub;
	std::ofstream tscript;

	//Resets the screen to look neater
	std::cout << "\033[H\033[2J";
	displaylist(head);
	tscript.open("transcript.txt", std::ofstream::app);

	node2 = head;

	std::cout << "Please enter the number of the entry you wish to remove:\n\n";
	tscript	<< "Please enter the number of the entry you wish to remove:\n\n";

	//Loop in case of incorrect entry
	while(1)
	{
		std::getline(std::cin, entry);

		tscript << entry + "\n\n";
		try
		{
			entrydoub = std::stod(entry);
		}
		catch(std::exception &e)
		{
			std::cout << "\n\nInvalid input, please try again:\n\n";
			tscript << "\n\nInvalid input, please try again:\n\n";
			continue;
		}


		node1 = searchbynum(head, entrydoub);

		if(node1 == NULL)
		{
			std::cout << " Try Again:\n\n";
			tscript << " Try Again:\n\n";
			continue;
		}
		else
			break;
	}

	//Loop for setting up previos node pointer
	while(node2->getnextpos() != node1)
	{
		node2 = node2->getnextpos();
	}

	node2->setnextpos(node1->getnextpos());
	delete node1;

	if(node2->getnextpos() == NULL)
	{
		return;
	}

	//Fixes numbers after removed item
	while(1)
	{
		node2 = node2->getnextpos();
		node2->setnum((node2->getnum())-1);

		if(node2->getnextpos() == NULL)
			break;
	}

	tscript.close();
}



//Allows the user to change an entry in the list
void editnode(startpos *head)
{
	startpos *node;
	std::ofstream tscript;
	std::string entry;
	double entrydoub;

	//Resets the screen to look neater
	std::cout << "\033[H\033[2J";
	displaylist(head);
	tscript.open("transcript.txt", std::ofstream::app);

	std::cout << "Please enter the number of the entry you wish to edit:\n\n";
	tscript	<< "Please enter the number of the entry you wish to edit:\n\n";

	//Loop in case of incorrect input
	while(1)
	{
		std::getline(std::cin, entry);
		tscript << entry + "\n\n";

		try
		{
			entrydoub = std::stod(entry);
		}
		catch(std::exception &e)
		{
			std::cout << "\n\nInvalid input, please try again:\n\n";
			tscript << "\n\nInvalid input, please try again:\n\n";
			continue;
		}

		node = searchbynum(head, entrydoub);

		if(node == NULL)
		{
			std::cout << " Try Again:\n\n";
			tscript << " Try Again:\n\n";
			continue;
		}
		else
			break;
		
	}

	//Loop for second entry
	std::cout << "\n\nPlease enter the new starting position in the same format as before:\n\n";
	tscript << "\n\nPlease enter the new starting position in the same format as before:\n\n";
	while(1)
	{
		std::getline(std::cin, entry);
		tscript << entry + "\n\n";

		//Incorrect input handling
		if(entry.length()<3 || (entry[1] != ',') || (entry[0]>'8'||entry[0]<'1') || ((entry[2]>'8'||entry[2]<'1')) || entry.length()>3)
		{
			std::cout << "\nInvalid input, please try again:\n\n";
			tscript << "\nInvalid input, please try again:\n\n";
			continue;
		}

		else
			break;
		

	}

	//Finally, changes the node according to the input
	node->setxcoord(entry[0]-48);
	node->setycoord(entry[2]-48);

	tscript.close();

}



//Deallocates the memory used by the list
void freelist(startpos *head)
{
	startpos *node, *temp;

	node = head->getnextpos();

	while(node != NULL)
	{
		temp = node;
		node = node->getnextpos();
		delete temp;
	}

	delete head;
}



//Returns the number of viable exits the passed spot on the board has for the knight
int howmanyexits(int xcoord, int ycoord, int board[8][8])
{
	int x, count = 0;
	int movesx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//Holds x values for all possible moves
	int movesy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };	//Sam for y values 

	for(x=0;x<8;x++)
	{
		if(board[ycoord + movesy[x]][xcoord + movesx[x]] == -1 && (ycoord + movesy[x] <= 7) 
			&& (ycoord + movesy[x] >= 0) && (xcoord + movesx[x] <= 7) && (xcoord + movesx[x] >= 0))
		{
			count++;
		}
	}
	
		
	return count;
}



//Finds element with the lowest value in an array (or one of them if there are ties)
int findlowest(int list[8])
{
	int x, low;

	low = 0;

	for(x=0;x<8;x++)
	{
		if(list[x] >= 9)
		{
			continue;
		}

		if(list[x] <= list[low])
		{
			low = x;
		}
	}


	return low;
}



//Adjusts the current position based on the number given
void updatecurrentpos(position *current, int num)
{
	int movesx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//Holds x values for all possible moves
	int movesy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };	//Sam for y values

	int x; 

	for(x=0;x<8;x++)
	{
		if(x == num)
		{
			current->setxcoord(current->getxcoord() + movesx[x]);
			current->setycoord(current->getycoord() + movesy[x]);
			return;
		}
	}
}



//Displays the board
void displayboard(board *currentboard)
{
	int x, y, count;
	std::ofstream tscript;

	//Opens stream to transcript
	tscript.open("transcript.txt", std::ofstream::app);

	for(x=0;x<8;x++)
	{
		for(y=0;y<8;y++)
		{
			printf("%2d  ", currentboard->boarda[x][y]);
			tscript << std::setw(2) << currentboard->boarda[x][y] << "  ";
		}

		std::cout << "\n\n";
		tscript << "\n\n";
	}

	//Closes transcript stream
	tscript.close();
}

