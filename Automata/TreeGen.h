//We will first define a tree data structure

//for a node of a tree 
#include"Tree.h"
#define CHAR 0
#define PIPE 1
#define PROD 2
#define CLOSURE 3
#define OPEN_B 4
#define CLOSE_B 5


int offset(int i, string S); // To get the next index
string SpaceRemove(string Reg);

void Update(stack < Node* > *T, int Mode);

Node *TG(string Reg, int start);

void TreeDisplay(Node *T);