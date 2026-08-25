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


void PrintLettersPattern(int number){
      for (int i = 65 + number - 1; i >= 65; i--)
      {
            for (int j = 1; j <= number - ((65 + number - 1) - i); j++)
            {
                  cout << char(i);  
            }
            cout << endl;
      }
}
 

int main(){

      PrintLettersPattern(ReadPositiveNumber("Enter The Number"));

      return 0;
}

