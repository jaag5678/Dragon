
#include"TreeGen.h"
int main() {
    
    //cout << "HIAY" << "\n";
    
    //First we need a string variable to store the regex
    string Reg;

    //Next we need to take in the input string along with spaces
    getline(cin, Reg);

    //Now call the regex tree gen function
    Node *Tree = TG(Reg, 0);
	

    TreeDisplay(Tree);
    //cout << Tree -> Content << endl;
	//cout << Tree -> Left -> Content << endl;
    //cout << Tree -> Right -> Content << endl;
    //cout << Tree -> Right -> Left -> Content << endl;
    //cout << Tree -> Right -> Right -> Content << endl;
    return 0;
}

