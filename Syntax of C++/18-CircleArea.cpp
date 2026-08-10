#include <iostream>
#include <cmath>
using namespace std;


// number 18

float CircleArea(short r){
      float p = 3.14;

      float area = p * pow(r,2);
      return area;
}
int main(){

      short r;

      cout << "plaese enter the r value" << endl;
      cin >> r;


      float area = CircleArea(r);
      //
      cout << "The Result is : " << ceil(area) << endl;

}