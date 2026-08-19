#include <iostream>
using namespace std;

void ReadNumebr(int &A , int &B){


    cout << "Enter  numbers One: ";
    cin >> A ;
    cout << "Enter  numbers Two: ";
    cin >> B;
}


void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void PrintNumber(int N1 , int N2){
    cout << "After swapping: num1 = " << N1 << ", num2 = " << N2 << endl;
}

int main() {


    int Num1 , Num2;

    ReadNumebr(Num1 , Num2);

    swapNumbers(Num1 , Num2);
    // Print After Swap
    PrintNumber(Num1 , Num2); 



    return 0;
}