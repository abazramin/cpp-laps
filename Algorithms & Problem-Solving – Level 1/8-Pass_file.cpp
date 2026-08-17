#include <iostream>
using namespace std;

enum enPassFail {Pass = 1 , Fail = 2};


int ReadMark(){
      int mark;

      cout << "Enter Your Mark ? ";
      cin >> mark;

      return mark;
}

enPassFail CheckPassFail(int mark){
      if (mark >= 50)
            return enPassFail::Pass;
      else 
            return enPassFail::Fail;
}


void PrintMark(enPassFail isPassed){
      if (isPassed == enPassFail::Pass)
            cout << "You'r Passed " << endl;
      else
            cout << "You'r Failed " << endl;
      
}

int main() {


      PrintMark(CheckPassFail(ReadMark()));

      return 0;
}