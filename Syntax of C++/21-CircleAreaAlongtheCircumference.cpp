#include <iostream>
#include <cmath>
using namespace std;

// numbers is 21
float CircleAreaAlongtheCircumference(short L){
      float p = 3.14;
      float area = (pow(L,2))/(4*p);
      return area;
}
int main(){


      short L;

      cout << "Plaese Enter Value Of L "  << endl;
      cin >> L;

      float area = CircleAreaAlongtheCircumference(L);

      int result = floor(area);

      cout << "The Result is : " << result << endl;

      return 0;
}