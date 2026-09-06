#include <iostream>
using namespace std;



int main()
{
      int Number = 0;
      cout << "Enter a number: ";
      cin >> Number;

      string Result = (Number % 2 == 0) ? "Even" : "Odd";
      cout << "The number is: " << Result << endl;



      int age = 20;
      
      string ageMessage = (age == 20) ? "You are an adult." : "You are a minor.";
      cout << ageMessage << endl;

      return 0;
}