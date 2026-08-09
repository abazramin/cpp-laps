#include <iostream>
#include <string>
using namespace std;


void printHello() {
    cout << "Hello, World!" << endl;
}


void displayMyCard(){
      cout << "Name: John Doe" << endl;
      cout << "Age: 30" << endl;
      cout << "Occupation: Software Developer" << endl;
}

void displayStars() {

        cout << "*****************\n";
        cout << "*****************\n";
        cout << "*****************\n";
}


void sumTwoNumbers(){
      int num1, num2;
      cout << "Enter first number: ";
      cin >> num1;
      cout << "Enter second number: ";
      cin >> num2;
      int sum = num1 + num2;
      cout << "The sum is: " << sum << endl;
}

int sumTwoNumbersWithint() {

      int num1, num2;
      cout << "Enter first number: ";
      cin >> num1;
      cout << "Enter second number: ";
      cin >> num2;
      int sum = num1 + num2;
    return sum;
}

int main() {
      int result = sumTwoNumbersWithint() + 13 + sumTwoNumbersWithint();
      cout <<"The Result is: " << result << endl;
}
    
