#include"TreeExtract.h"


//Table *CharHash = new Table[26];

bool Nullable(Node *T) {
    return T -> null;
}

set < int > FirstPosition(Node *T) {
    return T -> FirstPos;
}

set < int > LastPosition(Node *T) {
    return T -> LastPos;
}

set < int > FollowPosition(Node *T) {
    return T -> FollowPos;
}

/*
void UpdateTable(char C, int X) {
    CharHash[(int)(C - 'a')].Num.insert(X);
}
*/
void UpdateDetails(Node *T) {
    //The first part of this function is to understand that the leaaves have immediate vaules to the details and the 
    //Subsequent nodes have detials derived recursively from them
    //Note that we also need to number the leaves in order
    //For that we could use a static variable
    static int Z = 1;

    //cout << T -> Content << endl;
    if(!(T -> Left) && !(T -> Right)) {
        T -> null = false;
        //cout << "HI" << endl;
        T -> H.push_back(2);
        cout << T -> Content << endl;
        T -> FirstPos.insert(Z);
        //cout << "HI" << endl;
        T -> LastPos.insert(Z);
        //UpdateTable(T -> Content, Z);
        Z++;
        
        //We also could keep a simple hash table to store the mapping of char to numbers
        //cout << T -> Content << endl;
        return; 
    }
    
    if(T -> Left)
        UpdateDetails(T -> Left);
    if(T -> Right)
        UpdateDetails(T -> Right);

    set < int > X, Y;
    set < int > :: iterator I;
    X.clear();
    Y.clear();
    //For parent nodes the update details will be specific to specific operators    
    switch(T -> Content) {
        case '|': {
                    T -> null = Nullable(T -> Left) | Nullable(T -> Right);
                    
                    //For first pos
                    if(T -> Left)
                        X = FirstPosition(T -> Left);
                    if(T -> Right)    
                        Y = FirstPosition(T -> Right);

                    for(I = X.begin(); I != X.end(); I++) 
                        T -> FirstPos.insert(*I);
                    for(I = Y.begin(); I != Y.end(); I++)
                        T -> FirstPos.insert(*I);    
                    //We will replace all vectors with sets cause we dont need repetitions
                    //for(iterator i = X.begin(); i != X.end(); i++) 

                    //for last position
                    if(T -> Left)
                        X = LastPosition(T -> Left);
                    if(T -> Right)
                        Y = LastPosition(T -> Right);

                    for(I = X.begin(); I != X.end(); I++) 
                        T -> LastPos.insert(*I);
                    for(I = Y.begin(); I != Y.end(); I++)
                        T -> LastPos.insert(*I);    
                            


            }
        break;
        case '.':{
                    T -> null = Nullable(T -> Left) & Nullable(T -> Right);
                    
                    //For first postition
                    //If the left is Nullable then even the right can be at the first position of the subexp
                    if(Nullable(T -> Left)) {
                        cout << "KKK\n";
                        if(T -> Left)
                            X = FirstPosition(T -> Left);
                        if(T -> Right)    
                            Y = FirstPosition(T -> Right);

                        for(I = X.begin(); I != X.end(); I++) 
                            T -> FirstPos.insert(*I);
                        for(I = Y.begin(); I != Y.end(); I++)
                            T -> FirstPos.insert(*I);        
                    }
                    else {
                        X = FirstPosition(T -> Left);
                        for(I = X.begin(); I != X.end(); I++)
                            T -> FirstPos.insert(*I);
                    }

                    if(Nullable(T -> Right)) {
                        //cout << "KKK\n";
                        if(T -> Left)
                            X = LastPosition(T -> Left);
                        if(T -> Right)    
                            Y = LastPosition(T -> Right);

                        for(I = X.begin(); I != X.end(); I++) 
                            T -> LastPos.insert(*I);
                        for(I = Y.begin(); I != Y.end(); I++)
                            T -> LastPos.insert(*I);        
                    }
                    else {
                        X = LastPosition(T -> Right);
                        for(I = X.begin(); I != X.end(); I++)
                            T -> LastPos.insert(*I);
                    }
            }

        break;
        case '*':{
                    T -> null = true;

                    //First pos
                    //For kleene closure it will be sane as the node that succeeds it
                    T -> FirstPos = FirstPosition(T -> Left);

                    T -> LastPos = LastPosition(T -> Left);
            }

        break;
        default: {cout << "ZZ";}
    }    
return;

}