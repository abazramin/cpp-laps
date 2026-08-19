#include <iostream>
#include <cmath>
using namespace std;
// number 20


double ReadSquareSide(){
      double SquareSide;
      cout << "Please enter square side A ? " << endl;
      cin >> SquareSide;

      return SquareSide;
}

double CircleAreaInscribedinaSquare(double SquareSide){
      double p = 3.14;
      double area = (p * pow(SquareSide,2))/4;
      return area;
}


void PrintSquareSide(double result){
      cout << "The Result is : " << ceil(result) << endl;
}

int main () {


      PrintSquareSide(CircleAreaInscribedinaSquare(ReadSquareSide()));


      return 0;
}

