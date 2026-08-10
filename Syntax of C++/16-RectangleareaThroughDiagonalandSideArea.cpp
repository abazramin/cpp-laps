#include <iostream>
#include <cmath>
using namespace std;

// number 16
float RectangleareaThroughDiagonalandSideArea(float a, float d) {
      float area = a * sqrt(pow(d,2) - pow(a,2));
      return area;
}

int main(){

      float a , d;

      cout << "plaese enter a number" << endl;
      cin >> a;

      cout << "plaese enter d number" << endl;
      cin >> d;


      float area = RectangleareaThroughDiagonalandSideArea(a,d);


      cout << "the area is : " << area << endl; 

      return 0;
}