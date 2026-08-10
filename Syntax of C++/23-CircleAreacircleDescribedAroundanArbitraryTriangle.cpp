#include <iostream>
#include <cmath>
using namespace std;



float CircleAreacircleDescribedAroundanArbitraryTriangle(int a , int b , int c){
      float pi = 3.14;
      float p = (a + b + c) /4;

      float T = (a*b*c) / (4 * sqrt(p*(p-a) * (p-c)));

       T *= T;
      
      float area = pi * T;

      return area;
}

int main(){

      int a,b,c;

      cout << "Enter A , B , C Value" << endl;
      cin >> a ;
      cin >> b;
      cin >> c;
      //
      float area = CircleAreacircleDescribedAroundanArbitraryTriangle(a,b,c);
      cout << "The Result is : " << round(area) << endl;
      
      return 0;
}
