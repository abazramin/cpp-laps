#include <iostream>
#include <vector>

using namespace std;


vector<int> ReadNumber(){

      bool AddMore;
      int number;
      vector<int> vNumber;

      do
      {
            cout << "Enter The Number" << endl;
            cin >> number;

            vNumber.push_back(number);

            cout << "Do You Wand Add More Numbers : [1]Yes , [0]No ? " << endl;
            cin >> AddMore;

      } while (AddMore);
      
      return vNumber;
}


void PrintVectorNumber(vector<int> vNumber){

      cout << "\n ----------------------------------- " << endl;

      cout << "The Print Of Vector is :  " << endl;

       for (int Number : vNumber) {
            cout << Number << endl;
      }
}


int main(){

      PrintVectorNumber(ReadNumber());

      return 0;
}