#include <iostream>
#include <cmath>
using namespace std;
// number 20




float CircleAreaInscribedinaSquare(short A){
      float p = 3.14;
      float area = (p * pow(A,2))/4;
      return area;
}


int main () {


      short A;

      cout << "Plaese Enter D " << endl;
      cin >> A;


      float area = CircleAreaInscribedinaSquare(A);

      cout << "The Result is : " << ceil(area) << endl;


      return 0;
}

