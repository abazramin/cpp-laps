#include <iostream>
#include <cmath>
using namespace std;

// numbers is 21

int main(){

      float p = 3.14;
      short L;

      cout << "Plaese Enter Value Of L "  << endl;
      cin >> L;

      float area = (pow(L,2))/(4*p);

      int result = floor(area);

      cout << "The Result is : " << result << endl;

      return 0;
}