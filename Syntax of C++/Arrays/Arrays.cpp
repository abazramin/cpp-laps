#include <iostream>
using namespace std;


void ReadGreads(float greads[3]){
      cout << "Enter The Gread 1" << endl;
      cin >> greads[0];

      cout << "Enter The Gread 2" << endl;
      cin >> greads[1];

      cout << "Enter The Gread 3" << endl;
      cin >> greads[2];
}

float CalculateAvg(float greads[3]){
      return (greads[0] + greads[1] + greads[2]) / 3;
}

void printAvg(float greads[3]){
      float avg = CalculateAvg(greads);
      cout << "The Result is : " << avg << endl;
}

int main(){

      float greads[3];

      ReadGreads(greads);
      printAvg(greads);

      return 0;
}