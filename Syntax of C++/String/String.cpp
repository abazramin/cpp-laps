#include <iostream>
#include <string>
using namespace std;

int main() {
   string strone = "ABCDEF";


      string s1;
      cout << "Enter a string: ";
      cin.ignore(); // Clear the input buffer before using getline
      getline(cin, s1);

      cout << "You entered: " << s1 << endl;

      string sone = "5";
      string stwo = "10";

      int num1 = stoi(sone);
      int num2 = stoi(stwo);

      int sum = num1 + num2;

      cout << "Sum: " << sum << endl;

      string sthree = sone + stwo;
      cout << "Concatenated: " << sthree << endl;


    return 0;
}