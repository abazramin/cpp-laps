#include <iostream>
using namespace std;


float VaildateAge (int age) {

      if (age >= 18 && age <= 45)
      {
            /* code */
            return true;
      } 
      return false;
}

int main(){
      int age;
      cout << "Enter Your Age " << endl;
      cin >> age;

      float result = VaildateAge(age);

      if (result)
      {
            /* code */
            cout << " your Age is " << age << " That Means Vaild" << endl;
      } else {
            cout << " your Age is " << age << " That Means Not Vaild" << endl;

      }
      
}




#include <iostream>
using namespace std;

short ReadAge(){
      short age;
      cout << "Enter Your Age " << endl;
      cin >> age;

      return age;
}


short VaildateAge (short age) {

      if (age >= 18 && age <= 45)
            return true;

      return false;
}


void PrintAge(short result){
      if (result)
      {
            cout << " your Age is " << result << " That Means Vaild" << endl;
      } else {
            cout << " your Age is " << result << " That Means Not Vaild" << endl;

      }
}

int main(){
 

     return 0;
      
}