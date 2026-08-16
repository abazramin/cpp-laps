#include <iostream>
using namespace std;


void PrintNumebr1ToN(int N){

      cout << "What Number would be count ? Enter The Number " << endl;
      cin >> N;

      while (N <= 0)
      {
            /* code */
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }
      


      for (int i = 1; i <= N; i++)
      {
            /* code */
            cout << i << endl;
      }
      
}


int main(){


      int N;
     

      PrintNumebr1ToN(N);

      return 0;
}