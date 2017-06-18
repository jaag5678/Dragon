#include"Tree.h"

void TreeDisplay(Node *T) {
    //We will not write now a full flegded working of diaplying a tree
    // for now we will just hardcode the cout statements accordingly
    if(T == NULL)
        return;
    cout << T -> Content << " ";
    if(T -> Left) 
        cout << T -> Left -> Content << " ";
    if(T -> Right)
        cout << T -> Right -> Content;     
    cout << "\n";
    TreeDisplay(T -> Left);
    TreeDisplay(T -> Right);       
}

void TreeNodeDetails(Node *T) {
    if(T == NULL)
        return;

    cout << T -> Content << " " << T -> null << "\n";
    set < int > :: iterator I;

    cout << "First Position ";
    for(I = T -> FirstPos.begin(); I != T -> FirstPos.end(); I++)
        cout << *I << " ";
    cout << "\n";

    cout << "Last Position ";
    for(I = T -> LastPos.begin(); I != T -> LastPos.end(); I++)
        cout << *I << " ";
    cout << "\n";

    TreeNodeDetails(T -> Left);
    TreeNodeDetails(T -> Right);


}