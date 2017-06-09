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

Node* TG(string Reg, int start) {
    
    //For starters we will just consider the pipe operator and test on it
    //We will also ingnore the brackets for now
    //Later we will add brackets and see how to manipulate the stack as per our need

    stack < Node* > Stck;
    int current = -1;
    int op_scan = -1;
    for(size_t i = start; i < Reg.size(); i++) {
        
        switch((char)Reg[i]) {
            case ' ' : {continue;}
            break;

            case ')' : {return Stck.top();}
            break;

            case '(' : {//will call the same procedure again with the initial index from where to check
                        current = OPEN_B;
                        Node *T = new Node;
                        //cout << "Hiya" << endl;;
                        T = TG(Reg, i + 1);
                        //cout << "Biya" << endl;
                        Stck.push(T);
            }
            break;

            default : {  // This will be the default move 
                        Node *N = new Node;
                        N -> Content = (char)Reg[i];
                        N -> Left = NULL;
                        N -> Right = NULL;    
                        Stck.push(N);
            }
        }
        
        if(current == OPEN_B) {
            //Now need to find index where the nested expression ends
            //There are 2 things to keep in mind 
            //Firstly the bracket pairs we encounter, once they all pair up the next index is the desired one
            //Secondly the next char can be anything from another bracket to an operator to a character
            // For now it can only be either a Blank Space or a Pipe operator
            int o_b = 1;
            int c_b = 0;

            while(o_b != c_b) {
                i++;
                if((char)Reg[i] == '(')
                    o_b++;
                else if((char)Reg[i] == ')')
                    c_b++;    
            }
            //Now we just leave i as is, since the default increament will be done by the for loop for us
            cout << i << " " << Reg.size() << endl;
        }
        if(op_scan == PIPE) {
            current = -1;
            op_scan = -1;
            cout << "Here" << endl;
            cout << Stck.size() << endl;
            Update(&Stck, 1);
            continue;
        }
        if((char)Reg[i] == '|') {
            op_scan = PIPE;
            current = op_scan;
        }
        else {
            //default
            current = CHAR;
        }
    }
    //Note that no error checking is done for now. Later when it works for all operators we will consider error checking
    return Stck.top();
}

void TreeDisplay(Node *T) {
    //We will not write now a full flegded working of diaplying a tree
    // for now we will just hardcode the cout statements accordingly
    cout << T -> Content << " " << endl;
    cout << T -> Left -> Content << " " << endl;
    cout << T -> Right -> Content << " " << endl;;
    cout << T -> Right -> Left -> Content << " " << endl;;
    cout << T -> Right -> Right -> Content << " " << endl;;
    cout << endl;
}

/*
int main() {
    return 0;
}
*/

//#NOTE : Make sure to change all of the continuous if else statements to Switch for better understandibility of code