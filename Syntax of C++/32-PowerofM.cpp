#include <iostream>
#include <cmath>
using namespace std;



int PowerofM(int N , int M){
      float result = pow(N,M);
      return round(result);
}     


int main (){

      int N , M;

      cout << "Enter Value of N  " << endl;
      cin >> N ;
      cout << "Enter Value of N , M " << endl;
      cin >> M;

      int result = PowerofM(N,M);


      cout << "The Result is : " << result << endl;

      return 0;
}