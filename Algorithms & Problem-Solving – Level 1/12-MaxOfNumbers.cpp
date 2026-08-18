#include <iostream>
using namespace std;



void ReadNumbers(int & num1 , int & num2){
      cout << "Enter Number 1 " ;
      cin >> num1;
      cout << endl;
      cout << "Enter Number 2" ;
      cin >> num2;
}

int MaxOfNumbers(int num1 , int num2){
      if (num1 > num2)
            return num1;
      else 

      return num2;
}

void PrintMaxNumber(int max){
      cout << "The Max Number is : " << max << endl;
}

int main(){

      int num1;
      int num2;

      ReadNumbers(num1 , num2);
      PrintMaxNumber(MaxOfNumbers(num1 , num2));

      return 0;
}