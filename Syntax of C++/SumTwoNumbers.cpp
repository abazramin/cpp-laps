#include <iostream>
using namespace std;


int main(){

      short int a;
      short int b;

      cout << "Enter two numbers: ";
      cin >> a >> b;

      cout << "Sum of " << a << " and " << b << " is: " << a + b << endl;
      cout << "Difference of " << a << " and " << b << " is: " << a - b << endl;
      cout << "Product of " << a << " and " << b << " is: " << a * b << endl;
      cout << "Quotient of " << a << " and " << b << " is: " << a / b << endl;
      cout << "Remainder of " << a << " and " << b << " is: " << a % b << endl;

      return 0;
}