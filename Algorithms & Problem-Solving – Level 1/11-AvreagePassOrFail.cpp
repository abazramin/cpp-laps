#include <iostream>
using namespace std;


struct  stMarks
{
      int Mark1;
      int Mark2;
      int Mark3;
};

stMarks ReadNumbers(){
      
      stMarks Marks;

      cout << "Plz Enter Three Number To Get Avreage" << endl;

      cout << "Enter Number 1 : " << endl;
      cin >> Marks.Mark1;

      cout << "Enter Number 2 : " << endl;
      cin >> Marks.Mark2;

      cout << "Enter Number 3 : " << endl;
      cin >> Marks.Mark3;

      return Marks;
}

int SumOfNumbers(stMarks & marks){

      int result = marks.Mark1 + marks.Mark2 + marks.Mark3;

      return result;
}

float AvreageOfSums(stMarks sumofmarks){
      return (float)SumOfNumbers(sumofmarks) / 3;
}

bool isPassed(stMarks marks){
      if (AvreageOfSums(marks) >= 50)
            return true;


      return false;
}

void PrintPassFail(bool IsPassed){
      if (isPassed)
      {
            cout << "You'r Passed " << endl;
      } else {
            cout << "You'r Failed " << endl;
      } 
}


int main(){



      PrintPassFail(isPassed(ReadNumbers()));

      return 0;
}