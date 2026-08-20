#include <iostream>
using namespace std;




float ReadNumber(string Message)
{
    float Number = 0;  


    cout << Message << " ";
    cin >> Number;

    return Number;  
}

float SumNumberUntil99(float N){

      float sum = 0;

      while (N != -99)
      {
            sum += N;

            cout << "Enter Anthor Number , Most be != -99 " ;
            cin >> N;
      }
           
      return sum;
}


void PrintResult(float result){
      cout << "The Result is : " << result << endl;
}

int main(){

      float Number = ReadNumber("Enter a number (-99 to stop): ");
      PrintResult(SumNumberUntil99(Number));
      return 0;
}