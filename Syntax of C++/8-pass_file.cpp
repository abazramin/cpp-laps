#include <iostream>
using namespace std;
bool passFile(int mark){
      if (mark >= 50)
      {
            return true;
      }
      
      return false;
}


int main() {

      int mark;

      cout << "Enter Your Mark ? " << endl;
      cin >> mark;

      int result = passFile(mark);


      if(result){
            cout << "Pass " << endl;
      } else {
            cout << "File " << endl;
      }

      return 0;
}