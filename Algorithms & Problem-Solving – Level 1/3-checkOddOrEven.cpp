#include <iostream>
using namespace std;

enum enNumberType {  Odd =1, Even = 2 };

int ReadNumber(){

      int number;
      cout << "Enter a number : ";
      cin >> number;

      return number;
}

enNumberType CheckEvenOdd(int number){

      int result = number % 2;

      if(result == 0){
            return enNumberType::Even;
      }else{
            return enNumberType::Odd;
      }
}

void PrintResult(enNumberType numberType){
      if(numberType == enNumberType::Even){
            cout << "The number is Even" << endl;
      }else{
            cout << "The number is Odd" << endl;
      }
}

int main(){ 
      
      PrintResult(CheckEvenOdd(ReadNumber()));
     
}