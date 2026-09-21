#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
      //Function to generate a random number
      int randNum = rand() % (To - From + 1) + From;
      return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short
Cols)
{
      for (short i = 0; i < Rows; i++)
      {
            for (short j = 0; j < Cols; j++)
            {
                  arr[i][j] = RandomNumber(1, 10);
            }
      }
}


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
      for (short i = 0; i < Rows; i++)
      {
            for (short j = 0; j < Cols; j++)
            {
                  printf(" %0*d ", 2, arr[i][j]);
                  //cout << setw(3) << arr[i][j] << " ";
            }
            cout << "\n";
      }
}


bool IsNumberExsist(int Matrix1[3][3], int Number, short Rows, short Cols)
{
      for (short i = 0; i < Rows; i++)
      {
            for (short j = 0; j < Cols; j++)
            {
                  if (Matrix1[i][j] == Number)
                  {
                        return true;
                  };
            }
      }
      return false;
}

void getIntersetedNumber(int arr1[3][3] , int arr2[3][3] , short rows , short cols){
      
      int number = 0;

       for (short i = 0; i < rows; i++)
      {
            for (short j = 0; j < cols; j++)
            {
                  number = arr1[i][j];

                  if (IsNumberExsist(arr2 , number , 3 , 3))
                  {
                        cout << setw(3) << number << " " ;
                  }
            }
      }
}


int main()
{
      //Seeds the random number generator in C++, called only once
      srand((unsigned)time(NULL));

      int Matrix1[3][3] , Matrix2[3][3];
      FillMatrixWithRandomNumbers(Matrix1, 3, 3);
      FillMatrixWithRandomNumbers(Matrix2, 3, 3);

      cout << "\nMatrix1:\n";
      PrintMatrix(Matrix1, 3, 3);

      cout << "\nMatrix2:\n";
      PrintMatrix(Matrix2, 3, 3);


      cout << "\n The Intersetecd in 2 Matrix is : " << endl;
     getIntersetedNumber(Matrix1 , Matrix2 , 3 ,3);

      return 0;
}