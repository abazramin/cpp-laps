#include <iostream>
using namespace std;


void PrintNumebr1ToN(){
      
      int N;
      cout << "What Number would be count ? Enter The Number " << endl;
      cin >> N;

      while (N <= 0)
      {
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }
      
      for (int i = 1; i <= N; i++)
      {
            cout << i << endl;
      }
      
}


int main(){


      PrintNumebr1ToN();

      return 0;
}