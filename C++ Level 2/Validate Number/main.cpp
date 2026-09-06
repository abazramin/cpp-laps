#include <iostream>
using namespace std;



int readPositiveNumber(string Message)
{
      int Number = 0;  
      cout << Message << endl;
      cin >> Number;

    while (cin.fail()){
      
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid Input, Please Enter a Positive Number: ";
        cin >> Number;
    }  

    return Number;  
}

int main(){


      cout << "-------------------------------------"  << endl;
      cout << "Welcome to Validate Number Program"  << endl;
      int Number = readPositiveNumber("Please Enter a Positive Number");
      cout << "You Entered: " << Number << endl;

      return 0;
}