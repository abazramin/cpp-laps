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

int SumEvenNumbersfrom1toN(int N){
      int sum = 0;

      for (int i = 2; i <= N; i += 2)
      {
            sum += i;
      }
      return sum;     
}

void PrintSumEvenNumber(int result ){
      cout << "The Sum Of Even Number is : " << result << endl; 
}

int main(){


      PrintSumEvenNumber(SumEvenNumbersfrom1toN(ReadNumber()));

      
      return 0;
}