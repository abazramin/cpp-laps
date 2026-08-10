#include <iostream>
#include <cmath>
using namespace std;

float CircleAreaInscribedinanIsoscelesTriangle(int a , int b){
      float pi =3.14;
      float area = (pi * b * b / 4) * ((2 * a - b) / (2 * a + b));
      return area;
}


int main(){

     
      int a ,b;
      cout << "Plase Enter A" << endl;
      cin >> a;
      cout << "plase Enter B" << endl;
      cin >> b;

      float area = CircleAreaInscribedinanIsoscelesTriangle(a,b);


      int result = round(area);


      cout << "the result is : " << area <<endl;

      return 0;
}