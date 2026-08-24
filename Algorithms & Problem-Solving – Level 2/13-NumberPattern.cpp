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


void PrintNumberPattern(int number){
    for (int i = 1; i <= number; i++)
    {
      for (int j = 1; j <= i; j++)
      {
            cout << i <<" " ;
      }
      cout << endl;
    }
    
      
}


int main(){

      PrintNumberPattern(ReadPositiveNumber("Enter The Number"));

      return 0;
}