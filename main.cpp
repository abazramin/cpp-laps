#include <iostream>
#include <string>
using namespace std;





string Reverces(string name){

    string word = "";

    for (int i = name.length() - 1; i >= 0 ; i--)
    {
        word += name[i];
    }
    
    return word;
}


int main() {

    cout << Reverces("Abazr") << endl;

    return 0;
}