#include <iostream>
using namespace std;


void FibonacciSeriers(short lenght , short perv1 , short perv2){
      
      //
      short total;

      if (lenght > 0)
      {
            total = perv1 + perv2;
            cout << total << " " ;

            perv2 = perv1;
            perv1 = total;
            FibonacciSeriers(lenght - 1 , perv1 , perv2);
      }
}

int main(){

      FibonacciSeriers(10 , 0 , 1);

      return 0;
}