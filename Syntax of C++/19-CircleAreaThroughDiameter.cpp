#include <iostream>
#include <cmath>
using namespace std;


int main (){

      float p=3.14;

      int D;
      cout << "Plaese Enter D " << endl;
      cin >> D;


      float area = (p * pow(D,2))/4;

      cout << "The Result is : " << ceil(area) << endl;

      return 0;
}