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


int reversDigitNumber(int Number){

      int revers = 0;

      while (Number > 0)
      {
            revers *= 10;
            revers +=  Number % 10; 
            Number = Number / 10;

      }    

      return revers;
}

bool IsPalindrome(int Number)
{
    return Number == reversDigitNumber(Number);
}

void PrintResult(int Number)
{
    if (IsPalindrome(Number))
    {
        cout << "The Number " << Number << " is Palindrome" << endl;
    }
    else
    {
        cout << "The Number " << Number << " is Not Palindrome" << endl;
    }
}


int main()
{
    PrintResult(ReadPositiveNumber("Enter The a Number"));

    return 0;
}