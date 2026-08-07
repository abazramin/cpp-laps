#include <iostream>
#include <cmath>
using namespace std;
// number 20
int main () {

      float p = 3.14;
      short A;

      cout << "Plaese Enter D " << endl;
      cin >> A;


      float area = (p * pow(A,2))/4;

      cout << "The Result is : " << ceil(area) << endl;


      return 0;
}

