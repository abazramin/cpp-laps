#include <iostream>
#include <cmath>
using namespace std;


void ReadRectangleareaThroughDiagonalandSideArea(float &Length , float &Width){
    cout << "Enter the length of the rectangle: " << endl;
    cin >> Length;
    cout << "Enter the  width of the rectangle" << endl;
    cin >> Width;
}




// number 16
float CalculateRectangleareaThroughDiagonalandSideArea(float a, float d) {
      float area = a * sqrt(pow(d,2) - pow(a,2));
      return area;
}



void PrintRectangleareaThroughDiagonalandSideArea(float result){
    cout << "The Calculate Of Rectangle Area is : "  << result << endl;
}

int main(){

      float a , d;

      ReadRectangleareaThroughDiagonalandSideArea(a,d);
      PrintRectangleareaThroughDiagonalandSideArea( CalculateRectangleareaThroughDiagonalandSideArea(a,d));

      return 0;
}