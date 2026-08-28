#include <iostream>
using namespace std;


enum enPrefactNotPerfact { Perfact = 1, NotPerfact = 2 };

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

enPrefactNotPerfact CheckPrefact(int Number)
{
    int sum = 0;
    for (int Counter = 1; Counter < Number; Counter++)
    {
        if (Number % Counter == 0)  {
            sum += Counter;
            if(sum == Number){
                return enPrefactNotPerfact::Perfact;
            }
        }
    }

    return enPrefactNotPerfact::NotPerfact;  
}

void PrintNumberType(int Number)
{
        if (CheckPrefact(Number) == enPrefactNotPerfact::Perfact)
        {
            cout << "The number "<< Number << " is Perfact\n";
        } else {
            cout << "The number "<< Number << " is Not Perfact\n";
        }   
}



int main()
{

    PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  
}