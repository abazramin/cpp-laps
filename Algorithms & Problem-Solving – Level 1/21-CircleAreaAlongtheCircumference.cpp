#include <iostream>
#include <cmath>
using namespace std;

double ReadCircumference() 
{

      double Circumference;

      cout << "Plaese Enter Value Of Lone "  << endl;
      cin >> Circumference;

      return Circumference;
}

double CircleAreaAlongtheCircumference(double Circumference){
      double pi = 3.14;
      double area = (Circumference * Circumference)/(4*pi);
      return area;
}


void PrintCircumference(double result){
      cout << "The Result is : " << result << endl;
}
int main(){

      PrintCircumference(CircleAreaAlongtheCircumference(ReadCircumference()));
      return 0;
}