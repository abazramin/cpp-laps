#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message << endl;  
        cin >> Number;  
    } while (Number <= 0);  

    return Number;  
}



void reversDigitNumber(int Number){

      int revers = 0;

      while (Number > 0)
      {
            revers =  Number % 10; 
            Number = Number / 10;

            cout << revers ;
      }    
}



int main(){

      reversDigitNumber(ReadPositiveNumber("Enter The Positive Number "));
      return 0;
}