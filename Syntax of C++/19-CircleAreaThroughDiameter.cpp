#include <iostream>
#include <cmath>
using namespace std;


float CircleAreaThroughDiameter(short D){
       float p=3.14;
       float area = (p * pow(D,2))/4;
       return area;
}


int main (){


      int D;
      cout << "Plaese Enter D " << endl;
      cin >> D;


      float area = CircleAreaThroughDiameter(D);

      cout << "The Result is : " << ceil(area) << endl;

      return 0;
}