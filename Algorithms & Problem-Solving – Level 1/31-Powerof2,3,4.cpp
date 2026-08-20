#include <iostream>
#include <cmath>
using namespace std;


int ReadPowerNumber(){

      int Number;
      cout << "Enter The Number " << endl;
      cin >> Number;

      while (Number <= 0)
      {
            cout << "Must Be Enter Postive Number !" <<endl;
            cin >> Number;
      }

      return Number;
}


int CalculatePowerNumber(int Number , int  power){

    int result = 1;

    for (int i = 1; i <= power; i++)
    {
        result *= Number;
    }

    return result;
}


void PowerOfNumbers(int result){
      cout << "Result is : " << result << endl;
}

int main (){

    PowerOfNumbers(CalculatePowerNumber(ReadPowerNumber() , 3));

      return 0;
}
