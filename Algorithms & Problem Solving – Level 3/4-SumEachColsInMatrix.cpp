#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>    

using namespace std;



int RandomNumbers(int From , int To){
      return rand() % (To - From + 1) + From;
}

void FillMatrixArray(int arr[3][3] , short rows , short cols){
      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  arr[i][j] = RandomNumbers(1,100);
            }     
      }  
}

void PrintMatrixArray(int arr[3][3] , short rows , short cols){

      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  cout << setw(3) << arr[i][j] << "  ";
            }
            cout << endl;
      }
      
}

int SumCols(int arr[3][3] , short rows , short cols){

      int sum = 0;

      for (int row = 0; row < rows; row++)
      {
            sum += arr[row][cols];
      }

      return sum;
}

void PrintSumCols(int arr[3][3] , short rows , short cols){

      for (int row = 0; row < cols; row++)
      {
            cout << "Col " << row + 1
            << " | Sum: " << SumCols(arr, cols, row)
            << endl;
      }
}

int main(){

      srand((unsigned)time(NULL));

      int arr[3][3];


      FillMatrixArray(arr , 3 ,3);

      cout << "Print Matrix Array " << endl;
      PrintMatrixArray(arr ,3, 3);

      cout << endl;
      PrintSumCols(arr , 3 , 3);


      return 0;
}