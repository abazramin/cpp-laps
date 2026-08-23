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



int SumDigitNumber(int Number){

      int revers = 0;
      int sum  = 0;

      while (Number > 0)
      {
            revers =  Number % 10; 
            Number = Number / 10;
            //
            sum += revers;
      }    

      return sum ;
}



int main(){

      cout << "\n " << SumDigitNumber(ReadPositiveNumber("Enter The Positive Number "));
      return 0;
}