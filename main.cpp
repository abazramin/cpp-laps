#include <iostream>
#include <string>
using namespace std;




void function1(int &a){
    ++a;
}

string Reverces(string name){

    string word = "";

    for (int i = name.length() - 1; i >= 0 ; i--)
    {
        word += name[i];
    }
    
    return word;
}


int main() {

    int a = 10;


    function1(a);



    cout << a << endl;

    return 0;
}