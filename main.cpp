

//main.cpp
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "startpos.h"
#include "functions.h"
#include "stack.h"

int main()
{
	//Declarations
	std::string inpt;
	startpos *ptr;
	startpos *head = new startpos;	//Starting node for the linked list
	stack *mystack = new stack;		//Creates a stack instance 	
	std::ofstream tscript;


	//Set up for later logic
	head->setnextpos(NULL);

	//This just erases the old data on the file if it already exists
	tscript.open("transcript.txt", std::ofstream::trunc);
	tscript.close();

	//Opens up output file 
	tscript.open("transcript.txt", std::ofstream::app);

	//Resets the screen to look neater
	std::cout << "\033[H\033[2J";

	//Starting prompt
	std::cout << "Please enter a list of initial positions in the format 'X,Y'";
	tscript << "Please enter a list of initial positions in the format 'X,Y'";		//For transcript
	std::cout << " one at a time.\nEnter 'Q' when you are finished:\n\n";
	tscript << " one at a time.\nEnter 'Q' when you are finished:\n\n";				//For transcript	


	//Loop for taking input
	while(1)
	{
		//Takes input
		std::getline(std::cin, inpt);
		tscript << inpt + "\n";

		//Finished with entry
		if(inpt == "Q")
		{
			break;
		}

		//Incorrect input handling
		if(inpt.length()<3 || (inpt[1] != ',') || (inpt[0]>'8'||inpt[0]<'1') || ((inpt[2]>'8'||inpt[2]<'1')) || inpt.length()>3)
		{
			std::cout << "\nInvalid input, please try again:\n\n";
			tscript << "\nInvalid input, please try again:\n\n";
			continue;
		}

		//Calls add funtion (-48 on inputs to adjust ascii value)
		addpos(head,inpt[0]-48,inpt[2]-48); 

	}

	std::cout << "\n\n"; 
	tscript << "\n\n";

	//Loop for allowing the user to change the list
	while(1)
	{
		//Resets the screen to look neater
		std::cout << "\033[H\033[2J";
		tscript.close();	//Closes this stream so the function can open its own without issues 
		displaylist(head);
		tscript.open("transcript.txt", std::ofstream::app);	//Reopens when done,
		//This method avoids passing the stream as an argument if that's even possible

		//Display instructions for editing the list
		std::cout << "\n\nWould you like to make changes to the list?\n";
		std::cout << "Enter '1' to add an entry, '2' to remove one, or '3' to edit an entry.\n";
		std::cout << "If finished, enter 'Q' to continue.\n\n";
		tscript << "\n\nWould you like to make changes to the list?\n";
		tscript << "Enter '1' to add an entry, '2' to remove one, or '3' to edit an entry.\n";
		tscript << "If finished, enter 'Q' to continue.\n\n";

		//Takes input
		std::getline(std::cin, inpt);
		tscript << inpt + "\n";

		if(inpt == "1")
		{
			tscript.close();
			addnode(head);
			tscript.open("transcript.txt", std::ofstream::app);
		}
		
		else if(inpt == "2")
		{
			tscript.close();
			removenode(head);
			tscript.open("transcript.txt", std::ofstream::app);
		}

		else if(inpt == "3")
		{
			tscript.close();
			editnode(head);
			tscript.open("transcript.txt", std::ofstream::app);
		}

		if(inpt == "Q")
		{
			break;
		}

	}


	//Sets the index ptr to the head of the list
	ptr = head;

	//Loop for dipslaying the final boards
	while(1)
	{
		//Resets the screen to look neater
		std::cout << "\n\n\n";
		std::cout << "\033[H\033[2J";
		tscript << "\n\n\n";

		//Breaks once finished
		if(ptr->getnextpos() == NULL)
			break;

		//Points index to next starting position and runs the Knight's Tour algorithm 
		else
		{
			ptr = ptr->getnextpos();

			//Calls Tour algorithm
			tscript.close();
			findpath(ptr, mystack);
			tscript.open("transcript.txt", std::ofstream::app);

			//Display for each board
			std::cout << "\n\n" << ptr->getnum() << ":  " << "Starting Position:  " << ptr->getxcoord() << "," << ptr->getycoord();
			tscript << "\n\n" << ptr->getnum() << ":  " << "Starting Position:  " << ptr->getxcoord() << "," << ptr->getycoord();
			std::cout << "\n\nPress enter to continue...";
			tscript << "\n\nPress enter to continue...";
			std::getline(std::cin, inpt);
		}
	}

	tscript.close();	//Closes file stream
	freelist(head);		//Deallocates list memory
	delete mystack;

	return 0;        
}