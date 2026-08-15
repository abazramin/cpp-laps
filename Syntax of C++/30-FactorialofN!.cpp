#include <iostream>
using namespace std;


void  FactorialofN(int N){

      for (int i = N; i >= 1; i--)
      {
            /* code */

          int Fac =  i *= i - 1;

          cout << Fac << endl;

      }
      
}


int main(){

      cout << "Hello ! " << endl;

      FactorialofN(7);


      return 0;
}