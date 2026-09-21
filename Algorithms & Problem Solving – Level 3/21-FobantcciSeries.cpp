#include <iostream>
using namespace std;


void FibonacciSeriers(short lenght){
      //
      short first = 1;
      short secound = 0;
      short total;

      for (short i = 1; i < lenght; ++i)
      {
            total = first + secound;
            cout << total << " " ;

            secound = first;
            first = total;
      }
}

int main(){

      FibonacciSeriers(10);

      return 0;
}