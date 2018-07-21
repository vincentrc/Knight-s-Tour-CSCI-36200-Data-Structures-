
//functions.h
#ifndef functions_H
#define funtions_H

#include "startpos.h"
#include "stack.h"

//Function definitions
void *addpos(startpos *head, int x, int y);
void displaylist(startpos *head);
void addnode(startpos *head);
void removenode(startpos *head);
void editnode(startpos *head);
startpos *searchbynum(startpos *head, double num);
void freelist(startpos *head);
void findpath(startpos *start, stack *mystack);
int howmanyexits(int xcoord, int ycoord, int board[8][8]);
int findlowest(int list[8]);
void updatecurrentpos(position *current, int num);
void displayboard(board *currentboard);

#endif