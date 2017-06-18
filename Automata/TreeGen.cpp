#include"TreeGen.h"

int offset(int i, string Reg) {
    int o_b = 1;
    int c_b = 0;

    while(o_b != c_b) {
        if(i >= Reg.size())
            return i;
        i++;
        if((char)Reg[i] == '(')
            o_b++;
        else if((char)Reg[i] == ')')
            c_b++;                
    }
    return i;
}

string SpaceRemove(string Reg) {
    //I dont think we can do in place removal without our algorithm being O(n^2)
    //So we will use memory 
    string Temp;
    for(size_t i = 0; i < Reg.size(); i++) {
        if((char)Reg[i] == ' ')
            continue;
        Temp.push_back(Reg[i]);    
    }
    Reg.clear();
    for(size_t i = 0; i < Temp.size(); i++)
        Reg.push_back(Temp[i]);
    return Reg ;   
}

Node* SetNode(char C) {
    Node *T = new Node;
    T -> Content = C;
    T -> Left = NULL;
    T -> Right = NULL;
    return T;
}

void Update(stack < Node* > *T, int mode) {
    
    switch(mode) {
        case 1: {
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
        break;
        case 2: {
                Node *X = T -> top();
                T -> pop();

                Node *Y = new Node;
                Y -> Content = '.';
                
                Node *Z = T -> top();
                T -> pop();

                Y -> Right = X;
                Y -> Left = Z;
                T -> push(Y);

                //cout << "HEY\n";
        }
        break;
        case 3: {
                Node *X = T -> top();
                T -> pop();

                Node *Y = T -> top();
                T -> pop();

                X -> Right = NULL;
                X -> Left = Y;

                T -> push(X);
        }
    }
    return ;
}


Node* TG(string Reg, int start) {
    
    //THIS IS DONE CURRENTLY: REPORT IF ANY BUGS :)
    //Today we need to work on incorporating the product operator
        //Note that its not that a complicated thing to achieve, just that corner cases need to be considered before
        //Coding for the same

        //#1 if i get a char after a char or a whitespace => Product operator
        //#2 If i find a bracket after immediate char => Product operator
        //#3 Product operator given more precedence than pipe operator
        //#4 Order of checking will matter greatly here since product needs to be considered first
        //#5 Lookahead need not be required even for this operator since there is no ambiguity
        //#6 Switch needs to be modified to just chekc the previous char state and then gg

        //#7 Note that we still use the advantage of having only 3 elements in stack

    Reg = SpaceRemove(Reg);

    stack < Node* > Stck;
    int current = -1;
    int op_scan = -1;

    for(size_t i = start; i < Reg.size(); i++) {
        
        //A switch statement to:
        // #1 See char type
        // #2 If bracket found Recursively call the fucntion again and set character to type CHAR
        
        switch((char)Reg[i]) {
            case ' ' : {continue;}
            break;

            case ')' : {
                    //Return to previous fucntion that called the status of the top of stack
                    //Note that the stack always will have one element in the end of the expression
                    //cout << "JZJZ\n";
                    return Stck.top();}
            break;

            case '(' : {//will call the same procedure again with the initial index from where to check
                        //Here we see if the before char was indeed a character or not
                        if(current == CHAR)
                            op_scan = PROD;
                        current = OPEN_B;
                        //cout << "Biya" << endl;
                        Stck.push(TG(Reg, i + 1));
                        i = offset(i, Reg);
                        current = CHAR;
            }
            break;

            default : {
                        switch((char)Reg[i]) {
                            case '|': {op_scan = PIPE;
                                        current = PIPE;
                                    }
                            break;

                            case '*': {op_scan = CLOSURE;
                                        current = CLOSURE;}
                            break;

                            default : {if(current == CHAR) //Sanity check if previous was a char
                                        op_scan = PROD;
                                        //cout << i << "k" << "\n";   
                                        current = CHAR;   
                                    }            
                        }
                        Stck.push(SetNode(Reg[i]));
                    }
            }
        
        //Will convert below 2 if statements to switch statements later
        if(op_scan == PIPE && current == CHAR) {

            //IF its pipe we know its gonna be great with it ahead. But we need to notice that 
            //The subseqent exp can be "bcdef" which all need to be combined before doing this op
            //We can prevent all this if we just make a proper exp without white spaces.
            //Or we can directly loop in and come out when the part is not a char or space :)
            //However the code wont be written properly as prod is also called elsewhere

            int j = i + 1;
            bool ch = 0;
            while(j < Reg.size()) {
                if((char)Reg[j] == ' ') {
                    j++;
                    continue;
                }
                if((char)Reg[j] == '*') {
                    ch = 1;
                    Stck.push(SetNode(Reg[j]));
                    Update(&Stck, 3);
                    j++;
                    continue;
                }
                else if(isalpha((char)Reg[j])) {
                    ch = 1;
                    Stck.push(SetNode(Reg[j]));

                    //This code snippet chekcs forward for Kleene Closure before doing product
                    //If it exists update stack for the same and then update for product
                    if((j + 1) < Reg.size()) {
                        if((char)Reg[j + 1] == '*') {
                            Stck.push(SetNode(Reg[j + 1]));
                            Update(&Stck, 3);
                            j++;
                        }
                    }

                    Update(&Stck, 2);
                    j++;
                    continue;
                }    
                else if((char)Reg[j] == '(') {
                    ch = 1;
                    Stck.push(TG(Reg, j + 1));
                    j = offset(j, Reg);
                    
                    if((j + 1) < Reg.size()) {
                        if((char)Reg[j + 1] == '*') {
                            Stck.push(SetNode(Reg[j + 1]));
                            Update(&Stck, 3);
                            j++;
                        }
                    }
                    
                    Update(&Stck, 2);
                    //cout << Stck.size() << "h\n" << j << endl;;
                    //TreeDisplay(Stck.top());
                    
                    j++;
                    continue;
                } 
                break;
            }
            if(ch)
                i = j - 1;
            current = -1;
            op_scan = -1;
            Update(&Stck, 1);
        }
        else if(op_scan == PROD) {
            if((i + 1) < Reg.size()) {
                if((char)Reg[i + 1] == '*') {
                    Stck.push(SetNode(Reg[i + 1]));
                    Update(&Stck, 3);
                    i++;
                }
            }
            Update(&Stck, 2);
            current = CHAR; //Since if we find another char ahead then that too is to be multiplied with this
            op_scan = -1;
        }
        else if(op_scan == CLOSURE) {
            Update(&Stck, 3);
            current = CHAR;
            op_scan = -1;
        }
 
    }
    return Stck.top();
}




//#NOTE : Make sure to change all of the continuous if else statements to Switch for better understandibility of code
//#NOTE : The current code is not so readable, will make sure to organize it after today's work