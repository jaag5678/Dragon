//This header will have specific constructs to an automata
//The automata is modelled as a graph with multiple state transitions 
//The graph data structutre of Adjacency list will be used since DFA are rarely non-sparse garphs
#ifndef _FA_
#define _FA_

#include"Tree.h"

//Prototype structure of graph to be tested
typedef struct C {
   // struct C *P;
}C;

typedef struct State {
       vector < C* > Po;
       vector < C* > Pi;
}State;

typedef struct Edge {
    C *Dummy;
    State *Sfrom;
    State *Sto;
    char on;
}Edge;

typedef struct DeterminateFiniteAutomata {
    State *Start;
    int no_of_states;
    //For further details
    vector < char > Alphabet;
}DFA;

//Fucntions to create new state, link states to edges and vice versa
void CreateNewState();
void UpdateMachine(State * , State *, char C);

int StateExist(set < int > Combi); //Will return 1 if state already exists =, 0 otherise
void UpdateStateTable(set < int > Combi); 
Edge* UpdateEdge(State From, State To);
DFA* GenerateDFA(Node *T); 

//Set of Data access fucntions 

#endif

