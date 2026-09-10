#include <iostream>
using namespace std;



int main(){

      int arr[5] = {1,2,3,4,5};
      int *ptr = arr;


      // cout << " Address  " << *ptr << " >> "  << ptr + 1 << " >> " << ptr + 2 << " >> " << ptr + 3 << " >> " << ptr + 4 << " >> "  << "\n";

       for (int i = 0; i < 5; i++)
      {
           cout << ptr + i << " > " ;
      }



      cout << endl;

      // cout << " Values of   " << *ptr << " >> "  << *(ptr + 1) << " >> " << *(ptr + 2) << " >> " << *(ptr + 3) << " >> " << *(ptr + 4) << " >> "  << "\n";


      for (int i = 0; i < 5; i++)
      {
           cout << *(ptr + i) << " > " ;
      }
      

      return 0;
}