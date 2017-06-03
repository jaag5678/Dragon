#include"TreeGen.h"

void Update(stack < Node* > *T, int mode) {
    //For now we only have mode 1
    if(mode == 1) {
        Node *X  = T -> top();
        T -> pop();
        Node *Y = T -> top();
        T -> pop();
        Node *Z = T -> top();
        T -> pop();

        Y -> Right = X;
        Y -> Left = Z;
        T -> push(Y);
    }
    return ;
}

Node* TG(string Reg) {
    
    //For starters we will just consider the pipe operator and test on it
    //We will also ingnore the brackets for now
    //Later we will add brackets and see how to manipulate the stack as per our need

    stack < Node* > Stck;
    bool Brac = 0;
    for(size_t i = 0; i < Reg.size(); i++) {
        if((char)Reg[i] == ' ')
            continue;
        Node *N = new Node;
        N -> Content = (char)Reg[i];
        N -> Left = NULL;
        N -> Right = NULL;    
        Stck.push(N);
        if(Pipe) {
            Pipe = 0;
            Update(&Stck, 1);
            continue;
        }
        if((char)Reg[i] == '|')
            Pipe = 1;
    }
    //Note that no error checking is done for now. Later when it works for all operators we will consider error checking
    return Stck.top();
}
/*
int main() {
    return 0;
}
*/