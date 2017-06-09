//We will first define a tree data structure

//for a node of a tree 
#include"Combi.h"
#define CHAR 0
#define PIPE 1
#define PROD 2
#define CLOSURE 3
#define OPEN_B 4
#define CLOSE_B 5

// ? and + oeprator to be seen later

typedef struct Node {
    char Content; //Will define a character or an operator
    struct Node *Left;
    struct Node *Right;
}Node;

//The above structure is enough to construct a tree as required

//The fucntion TG that generates tree will require:
    // #1 Inserting nodes into a stack
    // #2 Removing nodes to generate a tree and placing the resultant node back

//We can use the stack variable to do the #1 Task
//We need a function just to modify the tree stack as per our need

void Update(stack < Node* > *T, int Mode);

Node *TG(string Reg, int start);

void TreeDisplay(Node *T);