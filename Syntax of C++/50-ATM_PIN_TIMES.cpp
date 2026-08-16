#include <iostream>
using namespace std;


bool ValidateATM_PIN(){

      int trying = 3;
      int Code;

      cout << "Enter Your Password " << endl;
      cin >> Code;

      while(Code != 1234){

            trying--;   

            if (trying == 0)
            {
                  /* code */
                  cout << "you out services " << endl;
                  return false;
            }

            cout << "Wrong Password , You Have a [ " << trying  << " ] , Try Again " << endl;
            cin >> Code;

      }

      cout << "Your Blance is 7000 $" << endl;
      return true;

}


int main(){

      ValidateATM_PIN();
}