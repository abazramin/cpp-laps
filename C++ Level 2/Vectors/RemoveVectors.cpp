#include <vector>
#include <iostream>

using namespace std;

int main()
{
      vector <int> vNumbers;

      // add
      vNumbers.push_back(10);
      vNumbers.push_back(20);
      vNumbers.push_back(30);
      vNumbers.push_back(40);
      vNumbers.push_back(50);

      cout << "Lenght is " <<vNumbers.size() << endl;
      // remove
     if (!vNumbers.empty())
     {
      vNumbers.pop_back();
      vNumbers.pop_back();
      vNumbers.pop_back();
      vNumbers.pop_back();
      vNumbers.pop_back();
     }
     
     // we can use clear function

     vNumbers.clear();


      cout << "Lenght is " <<vNumbers.size() << endl;


      cout << "Numbers Vector: \n\n";
      // ranged loop
      for (int & Number : vNumbers) {
            cout << Number << endl;
      }
      cout << endl;

      return 0;
}