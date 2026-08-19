#include <iostream>
#include <cmath>

using namespace std;

void ReadNumbers(double& equalSide, double& base)
{
    cout << "Please enter the equal side: ";
    cin >> equalSide;

    cout << "Please enter the base: ";
    cin >> base;
}

double CalculateInscribedCircleArea(double equalSide, double base)
{
    const double PI = 3.141592653589793;

    return (PI * base * base / 4.0) *
           ((2.0 * equalSide - base) /
            (2.0 * equalSide + base));
}

void PrintResult(double area)
{
    cout << "The result is: " << round(area) << endl;
}

int main()
{
    double equalSide, base;

    ReadNumbers(equalSide, base);

    PrintResult(
        CalculateInscribedCircleArea(equalSide, base)
    );

    return 0;
}