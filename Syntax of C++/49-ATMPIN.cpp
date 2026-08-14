#include <iostream>
using namespace std;

void ReadATMCode(int ATM){

      cout << "Enter Your ATM Code " << endl;
      cin >> ATM;

      while (ATM != 1234)
      {
            /* code */
            cout << "Wrong ATM Code , Try Again" << endl;
            cin >> ATM;
      }

      cout << "Yore Blance is 7000 $" << endl;
      
}





int main(){

      int atm;

      ReadATMCode(atm);


      return 0;
}