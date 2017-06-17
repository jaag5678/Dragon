#include<stack>
#include<string>
#include<iostream>
using namespace std;

typedef struct Node {
    char Content; //Will define a character or an operator
    struct Node *Left;
    struct Node *Right;
}Node;