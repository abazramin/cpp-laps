#include <iostream>
#include <cmath>
using namespace std;



int PowerofM(int N , int M){

    while (N <= 0)
    {
        /* code */
        cout << "Must Be Enter Postive Number !" <<endl;
        cin >> N;
    }
    


      float result = pow(N,M);
      return round(result);
}     


int PowerofMs(int N, int M)
{
    int result = 1;

    for (int i = 1; i <= M; i++)
    {
        result *= N;
    }

    return result;
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