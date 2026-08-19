
#include <iostream>
using namespace std;

short ReadAge(){
      short age;
      cout << "Enter Your Age " << endl;
      cin >> age;

      return age;
}


bool ValidateNumberInRange(int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}


void PrintAge(short age){
      if (ValidateNumberInRange(age , 18 , 45))
      {
            cout << " your Age is " << age << " That Means Vaild" << endl;
      } else {
            cout << " your Age is " << age << " That Means Not Vaild" << endl;

      }
}

int main(){
 
      PrintAge(ReadAge());


     return 0;
      
}