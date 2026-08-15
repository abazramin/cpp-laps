#include <iostream>
using namespace std;


int  FactorialofN(int N){
      int Fac = 1;
      for (int i = N; i >= 1; i--)
      {
            /* code */
         Fac = (Fac * i);
      }
      return Fac;  
}


void  FactorialofNWrong(int N){

      for (int i = N; i >= 1; i--)
      {
            /* code */
         i = i * i -1;
            
         cout << " : " <<i << endl;
      }

}

int main(){


      FactorialofNWrong(6);

      return 0;
}