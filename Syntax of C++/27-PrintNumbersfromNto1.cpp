#include <iostream>
using namespace std;


void PrintNumebrNTo1(int N){

      cout << "What Number would be count ? Enter The Number " << endl;
      cin >> N;

      while (N <= 0)
      {
            /* code */
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }
      
      

      for (int i = N; i >= 1; i--)
      {
            /* code */
            cout << i << endl;
      }
      
}


int main(){


      int N;
    

      PrintNumebrNTo1(N);

      return 0;
}