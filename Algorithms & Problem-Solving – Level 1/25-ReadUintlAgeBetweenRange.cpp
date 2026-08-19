#include <iostream>

using namespace std;

bool IsNumberInRange(int number, int from, int to)
{
    return number >= from && number <= to;
}

int ReadValidAge()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    while (!IsNumberInRange(age, 18, 45))
    {
        cout << "Please enter a valid age (18 - 45): ";
        cin >> age;
    }

    return age;
}

void PrintAge(int age)
{
    cout << "Your age is: " << age << " - Valid" << endl;
}

int main()
{
    PrintAge(ReadValidAge());

    return 0;
}