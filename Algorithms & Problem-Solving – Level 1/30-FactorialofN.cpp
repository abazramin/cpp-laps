#include <iostream>
using namespace std;

int ReadFactorial(){

      int Number;
      cout << "Enter The Factorial " << endl;
      cin >> Number;

      while (Number <= 0)
      {
            /* code */
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> Number;
      }

      return Number;
}



int  FactorialofN(int N){
      
      int Fac = 1;
      for (int i = N; i >= 1; i--)
      {
         Fac = (Fac * i);
      }
      return Fac;  
}


void PrintFactorialNumber(int result){
      cout << "The Factorial is : " << result << endl;
}

int main(){
      
      
      PrintFactorialNumber(FactorialofN(ReadFactorial()));

      return 0;
}