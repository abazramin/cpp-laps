#include <iostream>
#include <cmath>
using namespace std;

void PowerOfNumbers(){
      int num;
      cout << "Enter The Number " << endl;
      cin >> num;


      int num1 = round(pow(num,2));
      int num2 = round(pow(num,3));
      int num3 = round(pow(num,4));


      cout << "Result is : " << num1 << endl << num2 << endl << num3 << endl;
}

int main (){

    PowerOfNumbers();

      return 0;
}
