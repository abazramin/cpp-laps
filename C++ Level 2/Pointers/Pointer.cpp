#include <iostream>
using namespace std;


int sum(int a , int b){
      return (a + b);
}

int main(){

      int a = 10;
      int b = 20;


      cout << "Value of A is " << a << endl;
      cout << "Address is A " << &a << endl;
      
      int * p = &a;
      


      *p = 23;
      
      cout << "Poniter is " << *p << endl;

      
      
      
      a = 40;
      
      cout << "Value of A is " << a << endl;
      cout << "Poniter is " << *p << endl;

 
      return 0;
}