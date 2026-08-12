#include <iostream>
#include <string>
using namespace std;



void OneNumbers(int &n){
    n = 7000;
    cout << "The Numebr is : " << n <<  endl;
}


int main() {

    int x =10;

    OneNumbers(x);


    cout << endl << &x << endl;


    return 0;
}