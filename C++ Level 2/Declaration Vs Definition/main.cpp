#include <iostream>
using namespace std;

void sum(int a , int b); // Declaration


// function declaration
void add(int, int);


int main() {
      int a; // Declaration
      a = 10; // Definition
      
      cout << "Value of a: " << a << endl;
      
      return 0;
}

// function Definition
void add(int a, int b) {
cout << (a + b);
}


void sum(int a , int b) { // Definition
      cout << "Sum: " << a + b << endl;
}