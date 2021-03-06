#ifndef _TREE_
#define _TREE_

#include<stack>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

typedef struct Node {
    char Content; //Will define a character or an operator
    struct Node *Left;
    struct Node *Right;

    //We will need to add some extra details to the tree for the sake of our objective
    bool null; // if a node is nullable
    set < int > FirstPos; //Char that could come in the first position for the subexp rooted at node
    set < int > LastPos;  //Char that could end the exp rooted at node
    vector < int > H;
    //Note that we need to now consider every leaf as a unique element though the char might be the same
    //Which is why we have used int pointer, we will express terminals as numbers 
}Node;

typedef struct Table {
    char C;
    set < int > Num;
}Table;

//NOTE TO SELF -> THis part needs to be changed to vector later
extern Table *CharHash; //For now just the lowercase letters
                                //Later update for more than that
extern vector < set < int > > FollowPosTable;  
extern int NoOfChar;                              


void TreeDisplay(Node *T);
void TreeNodeDetails(Node *T);
void DisplayCharHash();
void FPosTable();
char GetChar(int I);
//int FollowPosExist(char C);

#endif