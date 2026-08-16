#include <iostream>
using namespace std;



int main(){
      
      int numebr;
      cout << "Plz Enter positve Number ? " << endl;
      cin >> numebr;

      while (numebr < 0)
      {
            /* code */
            cout << "Wrong ! , Number Must be Postive " << endl;
            cin >> numebr;
      }


      cout << "The number inputed is : " << numebr << endl;
      
}