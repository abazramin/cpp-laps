#include <iostream>
using namespace std;    



int main(){

      short int a;
      short int b;

      cout << "Enter two numbers: ";
      cin >> a >> b;

      cout << "Increment of " << a << " is: " << ++a << endl;
      cout << "Decrement of " << b << " is: " << --b << endl;

      return 0;
}