#include <iostream>
using namespace std;

void ReadRectangleArea(float &Length , float &Width){
    cout << "Enter the length of the rectangle: " << endl;
    cin >> Length;
    cout << "Enter the  width of the rectangle" << endl;
    cin >> Width;
}

int calculateRectangleArea(float a, float b) {
      return a * b;
}

void PrintRectangleArea(int result){
    cout << "The Calculate Of Rectangle Area is : "  << result << endl;
}

int main() {
    float length, width;

    ReadRectangleArea(length , width);

    PrintRectangleArea(calculateRectangleArea(length, width));

    return 0;
}