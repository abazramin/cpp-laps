#include <iostream>
using namespace std;


void PrintSumOddNumbersfrom1toN(int N){

      cout << "Enter The Number : " << endl;
      cin >> N;

      while (N <= 0)
      {
            /* code */
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }
      

      for (int i = 1; i <+ N; i = i + 2)
      {
            /* code */
            cout << i << endl;
      }
      
}


int main(){

      int N;
     


      PrintSumOddNumbersfrom1toN(N);

      
      return 0;
}