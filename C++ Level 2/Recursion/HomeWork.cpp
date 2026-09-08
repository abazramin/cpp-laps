#include <iostream>

using namespace std;

int ReadPositiveNumber()
{
    int number;

    cout << "Enter a positive number: ";
    cin >> number;

    while (number <= 0)
    {
        cout << "Must enter a positive number: ";
        cin >> number;
    }

    return number;
}

int ReadPower()
{
    int power;

    cout << "Enter the power: ";
    cin >> power;

    while (power < 0)
    {
        cout << "Power cannot be negative: ";
        cin >> power;
    }

    return power;
}

int CalculatePower(int number, int power)
{
    if (power == 0)
        return 1;
    else 
        return number * CalculatePower(number , power - 1);
}

void PrintResult(int result)
{
    cout << "The Result is: " << result << endl;
}

int main()
{
    int number = ReadPositiveNumber();
    int power = ReadPower();

    PrintResult(
        CalculatePower(number, power)
    );

    return 0;
}