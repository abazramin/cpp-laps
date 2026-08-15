#include <iostream>
using namespace std;


void PrintNumebr1ToN(int N){
      for (int i = 0; i <= N; i++)
      {
            /* code */
            cout << i << endl;
      }
      
}


int main(){


      int N;
      cout << "What Number would be count ? Enter The Number " << endl;
      cin >> N;

      PrintNumebr1ToN(N);

      return 0;
}