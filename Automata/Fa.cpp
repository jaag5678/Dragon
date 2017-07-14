#include"Fa.h"

vector < set < int > > StateTable;
vector < State > States;

void CreateNewState() {
    State *S = new State;
    States.push_back(*S);
}

void UpdateMachine(State *Sin, State *Sout, char x) {
   Edge *E = new Edge;
   E -> Dummy = new C; //I dont think we woud req this, since we just need the memory location of the pointer
   E -> Sfrom = Sout;
   E -> Sto = Sin;

   Sin -> Po.push_back(E -> Dummy);
   Sout -> Pi.push_back(E -> Dummy);

   return;
}

int StateExist(set < int > Combi) {
    for(size_t i = 0; i < StateTable.size(); i++) {
        if(Combi == StateTable[i])
            return i;
    }
    return -1;
}


void UpdateStateTable(set < int > Combi) {
    if(StateExist(Combi) == -1)
        return ;
    
    StateTable.push_back(Combi);
    CreateNewState();
}

DFA* GenerateDFA(Node *T) {

    //#Step 1: Add # to the hash table
    CharHash[26].C = (char)'#';
    CharHash[26].Num.insert(NoOfChar + 1);

    cout << "1" << endl;
    //#Step 2: Add additional node to this 
    Node *X = new Node;
    Node *Y = new Node;

    Y -> Content = '#';
    Y -> Left = NULL;
    Y -> Right = NULL;

    X -> Content = '.';
    X -> Left = T;
    X -> Right = Y;

    
    //First pos of the root will be that of simmilar to the product operator
    set < int > :: iterator I;

    //First pos of root will be first pos of it's left node
    for(I = T -> FirstPos.begin(); I != T -> FirstPos.end(); I++) 
        X -> FirstPos.insert(*I);
    
    cout << "2" << endl;

    //IF left node is null it means the grammar can accept even empty string so insert even that into the firstpos root
    if(T -> null)
        X -> FirstPos.insert(NoOfChar + 1);

    //The last pos would be this end char that we place to indicate that the string has matched    
    X -> LastPos.insert(NoOfChar + 1);    

    //Why did I do this?
    //IT goes from last pos of the node to left of root we made and it adds to it the end element of the grammar
    //Naturally after the last pos character the one that would follow it would also be the end char hence we did this
    //TO notify that the grammar accepts the exp specified by T
    cout << "3" << endl;

    for(I = T -> LastPos.begin(); I != T -> LastPos.end(); I++) { 
        //cout << "{";
        //cout << *I << " ";
        FollowPosTable[*I].insert(NoOfChar + 1);
        //cout << "}" << endl;
    }
    
    cout << "4" << endl;
    
    set < int > GG;
    GG.insert(NoOfChar + 1);

    FollowPosTable.push_back(GG);

    UpdateStateTable(X -> FirstPos);
    //WE start off by creating our first state (with the call to function above)
    //Chhose the firstpos of the state in the collection of states
    //Once we choose an element from the alphabet, we find out the follow pos that corresponds to all the index 
    //designated to that one element in the alphabet
    
    //To do this consistently for all new states, we need a ref to access the index corr to a new state from our state 
    //table. This will ensure that once this ref recahes the end, we know no more new states exist

    for(size_t i = 0; i < StateTable.size(); i++) {
        //First choose an alphabet from Hash Table
        for(size_t j = 0; j < 27; j++) {
            //For that char search equivalent hashed indexes and see if they match with those in state table set
            vector < int > S;
            set < int > :: iterator I1, I2;
            I1 = CharHash[j].Num.begin();
            I2 = StateTable[i].begin();

            while(I1 != CharHash[j].Num.end() && I2 != StateTable[i].end()) {
                if(*I1 == *I2) {
                    S.push_back(*I1);
                    I1++;
                    I2++;
                }
                else if(*I1 > *I2) 
                    I2++;
                else
                    I1++;        
            }
            set < int > Temp;
            set < int > :: iterator It;
            for(size_t k = 0; k < S.size(); k++) {
                for(It = FollowPosTable[S[k]].begin(); It != FollowPosTable[S[k]].end(); It++) {
                    Temp.insert(*It);
                }
            }

            UpdateStateTable(Temp);

            //Need to fetch the states from the collection of states, 
            //for that we can use stateexist func to return the index that has the location of state desired
            //The start state would be indicated by index i of the primary loop thru state table

            int k = StateExist(Temp);

            UpdateMachine(&States[i], &States[k], CharHash[j].C);
            //Update the graph by creating new edge and connecting states
            //make a function to do it, which gives 2 states and one edge as parameter
            //We can modify the existing state exsit to return the index of state whihc corresponds to 
            //index of the exact state we need in the vector of States we defined before
            //Note: States can come repetitively but not edges so we need to keep a track of states

        
        } 
    }


    DFA *D = new DFA;

    D -> Start = &States[0];
    D -> no_of_states = States.size();

    //Need to Complete

    

}