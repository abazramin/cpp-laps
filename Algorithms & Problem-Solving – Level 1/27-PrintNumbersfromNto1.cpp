#include <iostream>
using namespace std;


void PrintNumebrNTo1(){

      int N;
      
      cout << "What Number would be count ? Enter The Number " ;
      cin >> N;

      while (N <= 0)
      {
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }
      
      for (int i = N; i >= 1; i--)
      {
            cout << "\n" <<i << endl;
      }
      
}


int main(){

    

      PrintNumebrNTo1();

      return 0;
}