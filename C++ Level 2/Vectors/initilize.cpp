#include <iostream>
#include <vector>
using namespace std;


int main(){

      vector<int> vNumber = {1,2,3,4,5};

      cout << "Print First Vector" << endl;

      vNumber.push_back(6);
      vNumber.push_back(7);
      vNumber.push_back(8);
      vNumber.push_back(9);
      vNumber.push_back(10);


      for (int &n : vNumber)
      {
            cout << n << " " ;
      }
      
      cout << endl;


      vNumber.pop_back();
        cout << "Print After pop back" << endl;


         for (int &n : vNumber)
      {
            cout << n << " " ;
      }

      cout << endl;

      return 0;
}