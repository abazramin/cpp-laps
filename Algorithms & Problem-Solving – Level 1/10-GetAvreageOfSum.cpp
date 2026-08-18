#include <iostream>
using namespace std;


struct  stSumOfNumbers
{
      int number1;
      int number2;
      int number3;
};



stSumOfNumbers ReadNumbers(){
      
      stSumOfNumbers numbers;

      cout << "Plz Enter Three Number To Sum It" << endl;

      cout << "Enter Number 1 : " << endl;
      cin >> numbers.number1;

      cout << "Enter Number 2 : " << endl;
      cin >> numbers.number2;

      cout << "Enter Number 3 : " << endl;
      cin >> numbers.number3;

      return numbers;
}


int SumOfNumbers(stSumOfNumbers & numbers){

      int result = numbers.number1 + numbers.number2 + numbers.number3;

      return result;
}

float AvreageOfSums(stSumOfNumbers sumofNumbre){
      return (float)SumOfNumbers(sumofNumbre) / 3;
}

void PrintSumOfNumebrs(int result){
      cout << "The Result Of Numbers is : " << result << endl;
}



int main(){

      PrintSumOfNumebrs(AvreageOfSums(ReadNumbers()));

      return 0;
}