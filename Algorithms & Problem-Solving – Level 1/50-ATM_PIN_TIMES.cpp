#include <iostream>
using namespace std;




int ReadATM_PIN()
{
    int Code;

    cout << "Enter Your Password: ";
    cin >> Code;

    return Code;
}




bool ValidateATM_PIN(int Code)
{
    return Code == 1234;
}


bool LoginATM()
{
    int Trying = 3;

    int Code = ReadATM_PIN();

    while (!ValidateATM_PIN(Code))
    {
        Trying--;

        if (Trying == 0)
        {
            return false;
        }

        cout << "Wrong Password, You Have [ "
             << Trying
             << " ] Try Again\n";

        Code = ReadATM_PIN();
    }

    return true;
}




void PrintResult(bool IsValid)
{
    if (IsValid)
    {
        cout << "Your Balance is 7000 $" << endl;
    }
    else
    {
        cout << "You Are Locked" << endl;
    }
}




int main()
{
    bool IsValid = LoginATM();

    PrintResult(IsValid);

    return 0;
}