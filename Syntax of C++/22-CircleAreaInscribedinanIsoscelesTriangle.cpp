#include <iostream>
#include <cmath>
using namespace std;

int main(){

      float pi =3.14;
      int a ,b;

      cout << "Plase Enter A" << endl;
      cin >> a;
      cout << "plase Enter B" << endl;
      cin >> b;

      float area = (pi * b * b / 4) * ((2 * a - b) / (2 * a + b));


      int result = round(area);


      cout << "the result is : " << area <<endl;

      return 0;
}