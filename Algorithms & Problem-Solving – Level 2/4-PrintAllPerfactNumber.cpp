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

void Printallperfectnumbers(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrefact(i) == enPrefactNotPerfact::Perfact)
        {
            cout << "The number "<< i << " is Perfact\n";
        } 
    }
    
}

int main()
{

    Printallperfectnumbers(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  
}