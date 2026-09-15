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

int SumRow(int arr[3][3] , short rows , short cols){

      int sum = 0;

      for (int col = 0; col < cols; col++)
      {
            sum += arr[rows][col];
      }

      return sum;
}

void PrintSumRow(int arr[3][3] , short rows , short cols){

      for (int row = 0; row < rows; row++)
      {
            cout << "Row " << row + 1
            << " | Sum: " << SumRow(arr, row, cols)
            << endl;
      }
}

void SumSparetorArray(int arr[3][3]  ,short rows , short cols, int sumarr[3]){

      for (int row = 0; row < rows; row++)
      {
            sumarr[row] = SumRow(arr , row , cols);
      }
}


void PrintRowsSumArray(int arr[3], short Rows)
{
      cout << "\nThe the following are the sum of each row in the matrix:\n";

      for (short i = 0; i < Rows; i++)
      {
      cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
      }
}

int main(){

      srand((unsigned)time(NULL));

      int arr[3][3] , SumArr[3];


      FillMatrixArray(arr , 3 ,3);

      cout << "Print Matrix Array " << endl;
      PrintMatrixArray(arr ,3, 3);

      cout << endl;
      PrintSumRow(arr , 3 , 3);


      SumSparetorArray(arr , 3 , 3 ,SumArr);

      PrintRowsSumArray(SumArr , 3);

      return 0;
}