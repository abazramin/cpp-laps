#include <iostream>
using namespace std;


int  FactorialofN(int N){

    

      while (N <= 0)
      {
            /* code */
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }
      
      int Fac = 1;
      for (int i = N; i >= 1; i--)
      {
            /* code */
         Fac = (Fac * i);
      }
      return Fac;  
}




int main(){
      int N;
      cout << "Enter The Number : " << endl;
      cin >> N;

      
      cout << FactorialofN(N) << endl;

      return 0;
}