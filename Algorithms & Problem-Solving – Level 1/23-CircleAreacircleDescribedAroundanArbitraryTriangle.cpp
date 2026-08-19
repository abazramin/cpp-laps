#include <iostream>
#include <cmath>

using namespace std;

void ReadTriangleSides(double& a, double& b, double& c)
{
    cout << "Enter side A: ";
    cin >> a;

    cout << "Enter side B: ";
    cin >> b;

    cout << "Enter side C: ";
    cin >> c;
}

double CalculateCircumcircleArea(double a, double b, double c)
{
    const double PI = 3.141592653589793;

    double s = (a + b + c) / 2.0;

    double triangleArea =
        sqrt(s * (s - a) * (s - b) * (s - c));

    double radius =
        (a * b * c) / (4.0 * triangleArea);

    return PI * radius * radius;
}

void PrintResult(double area)
{
    cout << "The Result is: " << round(area) << endl;
}

int main()
{
    double a, b, c;

    ReadTriangleSides(a, b, c);

    PrintResult(
        CalculateCircumcircleArea(a, b, c)
    );

    return 0;
}