
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
      for (short i = 0; i < Rows; i++)
      {
            for (short j = 0; j < Cols; j++)
            {
                  //printf(" %0*d ", 2, arr[i][j]);
                  cout << setw(3) << arr[i][j] << " ";
            }
            cout << "\n";
      }
}


short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
      short NumberCount = 0;
      for (short i = 0; i < Rows; i++)
      {
            for (short j = 0; j < Cols; j++)
            {
                  if (Matrix1[i][j] == Number)
                  {
                        NumberCount++;
                  };
            }
      }
      return NumberCount;
}

bool isSparseMatrix(int arr[3][3] , short rows , short cols){
      short MatrixSize = rows * cols;
      return (CountNumberInMatrix(arr, 0, 3, 3) >= ceil((float)MatrixSize / 2));
}


int main()
{
      int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

      cout << "\nMatrix1:\n";
      PrintMatrix(Matrix1, 3, 3);

      int Number;
      cout << "\nEnter the number to count in matrix? ";
      cin >> Number;

      cout << "\nNumber " << Number << " count in matrix is "
      << CountNumberInMatrix(Matrix1, Number, 3, 3);



      if (isSparseMatrix(Matrix1, 3, 3))
            cout << "\nYes: It is Sparse\n";
      else
            cout << "\nNo: It's NOT Sparse\n";

      return 0;
}