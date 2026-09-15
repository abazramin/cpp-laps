#include <iostream>
#include <iomanip>
#include <cstdlib>    

using namespace std;


int RandomNumber(int from , int to){
      return rand() % (to - from + 1) + from;
}


void Fill2DArrayWithRandomNumber(int arr[3][3] , short rows , short cols){
      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  arr[i][j] = RandomNumber(1,100);
            }
            
      }
      
}



void Print2DArrayWithRandomNumber(int arr[3][3] , short rows , short cols){
      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  cout << setw(3) << arr[i][j] << "     ";
            }
            cout << endl;
      }
      
}


int main(){

      srand((unsigned)time(NULL));
      
      int arr[3][3];

      Fill2DArrayWithRandomNumber(arr , 3 , 3);


      Print2DArrayWithRandomNumber(arr , 3 ,3);

      return 0;
}