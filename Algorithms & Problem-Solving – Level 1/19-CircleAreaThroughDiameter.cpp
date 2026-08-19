#include <iostream>
#include <cmath>
using namespace std;

double ReadCircleAreaDiameter(){
      double Diameter;
      cout << "Plaese Enter Diameter " << endl;
      cin >> Diameter;

      return Diameter;
}

double CircleAreaThroughDiameter(double Diameter){
      const float p=3.14;
      double area = (p * pow(Diameter,2))/4;
      return area;
}


void PrintCircleAreaDiameter(float result){
      cout << "The Result is : " << ceil(result) << endl;

}

int main (){

      PrintCircleAreaDiameter(CircleAreaThroughDiameter(ReadCircleAreaDiameter()));

      return 0;
}