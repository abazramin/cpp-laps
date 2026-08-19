#include <iostream>
#include <cmath>
using namespace std;


void ReadCircleArea(short & r){
      cout << "plaese enter the r value" << endl;
      cin >> r;
}

float CalculteCircleArea(short r){
      float p = 3.14;

      float area = p * pow(r,2);
      return area;
}


void PrintCircleArea(float result){
      cout << "The Result is : " << ceil(result) << endl;

}
int main(){

      short r;

      ReadCircleArea(r);

      PrintCircleArea(CalculteCircleArea(r));

      return 0;

}