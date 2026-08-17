#include <iostream>
using namespace std;


int ReadNumber(){
      int Num;

      cout << "Enter The Number : " ;
      cin >> Num;

      return Num;
}

float HalfNumber(int num){
      return (float)num / 2;
}

void PrintHalfNumber(float halfNumber){
      cout << "\n Half Number is : " << halfNumber << endl;
}

int main(){
      PrintHalfNumber(HalfNumber(ReadNumber()));

      return 0;
}