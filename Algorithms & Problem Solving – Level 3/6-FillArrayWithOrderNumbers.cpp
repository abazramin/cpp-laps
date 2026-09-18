#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>    

using namespace std;



void FillMatrixArray(int arr[3][3] , short rows , short cols){

      short n = 1;

      for (short i = 0; i < rows; i++)
      {
            for (short j = 0; j < cols; j++)
            {
                  arr[i][j] = n;
                  n++;
            }     
      }  
}


void PrintMatrixArray(int arr[3][3] , short rows , short cols){

      for (short i = 0; i < rows; i++)
      {
            for (short j = 0; j < cols; j++)
            {
                  cout << setw(3) << arr[i][j] << "  ";
            }
            cout << endl;
      }
      
}



int main(){

      srand((unsigned)time(NULL));

      int arr[3][3];


      FillMatrixArray(arr , 3 ,3);

      cout << "Print Matrix Array " << endl;
      PrintMatrixArray(arr ,3, 3);

      return 0;
}