


#include <iostream>
using namespace std;


void PrintSumEvenNumbersfrom1toN(int N){
      for (int i = 0; i <+ N; i = i + 2)
      {
            /* code */
            cout << i << endl;
      }
      
}


int main(){

      int N;
      cout << "Enter The Number : " << endl;
      cin >> N;


      PrintSumEvenNumbersfrom1toN(N);
      return 0;
}