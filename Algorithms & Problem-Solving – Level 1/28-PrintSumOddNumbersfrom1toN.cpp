#include <iostream>
using namespace std;

int ReadNumber(){
      int N;

      cout << "Enter The Number : " << endl;
      cin >> N;

      while (N <= 0)
      {
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> N;
      }

      return N;
}

int SumOddNumbersfrom1toN(int N){
      int sum = 0;

      for (int i = 1; i <= N; i += 2)
      {
            sum += i;
      }
      return sum;     
}

void PrintSumODDNumber(int result ){
      cout << "The Sum Of Number is : " << result << endl; 
}

int main(){


      PrintSumODDNumber(SumOddNumbersfrom1toN(ReadNumber()));

      
      return 0;
}