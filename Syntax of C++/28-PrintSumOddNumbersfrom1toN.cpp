#include <iostream>
using namespace std;


void PrintSumOddNumbersfrom1toN(int N){
      for (int i = 1; i <+ N; i = i + 2)
      {
            /* code */
            cout << i << endl;
      }
      
}


int main(){

      int N;
      cout << "Enter The Number : " << endl;
      cin >> N;


      PrintSumOddNumbersfrom1toN(N);

      
      return 0;
}