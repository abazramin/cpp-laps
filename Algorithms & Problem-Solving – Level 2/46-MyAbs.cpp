#include <iostream>
using namespace std;


int ReadNagitveNumber(string Message)
{
    int Number = 0;  
    do
    {
      cout << Message << endl;  
      cin >> Number;  
    } while (Number >= 0);  

    return Number;  
}


float Absolute(int Number)
{
    if (Number < 0)
        return Number * -1;

    return Number;
}


int main(){



      cout << Absolute(ReadNagitveNumber("Enter The Abs Number Value"));
}