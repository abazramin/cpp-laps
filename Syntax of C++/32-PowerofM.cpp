#include <iostream>
#include <cmath>
using namespace std;

int main (){

      int N , M;

      cout << "Enter Value of N  " << endl;
      cin >> N ;
      cout << "Enter Value of N , M " << endl;
      cin >> M;

      float result = pow(N,M);


      cout << "The Result is : " << round(result) << endl;

      return 0;
}