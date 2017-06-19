#ifndef _TREE_EXTRACT_
#define _TREE_EXTRACT_

#include"Tree.h"

//Data structure to store mapping of char to number

//#THis is DONE for NOW
//Although slight testing and code optimization remains
//This header file will contain functions to extract details from the syntax tree generated viz.
//#1 Nullable
//#2 FirstPos
//#3 FollowPos

void UpdateDetails(Node *T);
void UpdateTable(char C, int X); // For the sake of Composed and abstract code, we keep this seperate function
bool Nullable(Node *T);
set < int > FirstPosition(Node *T);
set < int > LastPosition(Node *T);
set < int > FollowPosition(Node *T);

#endif

//Later we wull use those details to generate NFA and DFA enitirely from scratch

//But first we need some data structures to be designed to contain the abpve details of the syntax tree
//Read the dragon book tomorrow after gre stuff to get yourself ready to understand why and how it works
