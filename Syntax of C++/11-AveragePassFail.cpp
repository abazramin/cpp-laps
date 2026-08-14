#include <iostream>
using namespace std;





float calcAvreage(int one , int two , int three){
      return (one + two + three) / 3;
}

bool passFile(int avg){
      if (avg >= 50)
      {
            return true;
      }
      
      return false;
}

int main(){

      int one , two , three;

      cout << "Enter Mark One ? " << endl;
      cin >> one;

      cout << "Enter Mark Two ? " << endl;
      cin >> two;

      cout << "Enter Mark Three ? " << endl;
      cin >> three;

      int avg = calcAvreage(one , two , three);


      float result = passFile(avg);

      if (result)
      {
            /* code */
            cout << "Your Avg is : " <<avg << endl;
            cout << "Pass " << endl;
      } else{
            cout << "File " << endl;
      }
      
}