#include <iostream>
using namespace std;



int main(){

      int *ptrI;
      float *ptrF;

      // 
      ptrI = new int;
      ptrF = new float;

      // 
      *ptrI = 20;
      *ptrF = 12.43;


      // print 
      cout << ": " << *ptrI << endl;
      cout << ": " << *ptrF << endl;

      delete ptrF;
      delete ptrI;


       // print 
      cout << "\n\n: " << *ptrI << endl;
      cout << ": " << *ptrF << endl;


      return 0;
}