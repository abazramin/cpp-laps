#include <iostream>
using namespace std;


void clsRectangleArea(int a, int b) {
      int Area = a * b;
      cout << "Area of the rectangle: " << Area << endl;
}


int main() {
    int length, width;

    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;

    clsRectangleArea(length, width);

    return 0;
}