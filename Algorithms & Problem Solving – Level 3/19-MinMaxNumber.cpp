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
                  arr[i][j] = RandomNumber(1, 100);
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


int MinNumebrMatrix(int arr[3][3] , short rows , short cols){

      short number = 0;

      number = arr[0][0];

      for (short i = 0; i < rows; i++)
      {
            for (short j = 0; j < cols; j++)
            {

                 if (arr[i][j] < number)
                 {
                        number = arr[i][j];
                 }
                 
            }
      }

      return number;
}



int MaxNumebrMatrix(int arr[3][3] , short rows , short cols){

      short number = 0;

      number = arr[0][0];

      for (short i = 0; i < rows; i++)
      {
            for (short j = 0; j < cols; j++)
            {

                 if (arr[i][j] > number)
                 {
                        number = arr[i][j];
                 }
                 
            }
      }

      return number;
}




int main()
{
      //Seeds the random number generator in C++, called only once
      srand((unsigned)time(NULL));

      int Matrix1[3][3];
      FillMatrixWithRandomNumbers(Matrix1, 3, 3);


      cout << "\nMatrix1:\n";
      PrintMatrix(Matrix1, 3, 3);

      


      cout << "\n The Min Number in Matrix is : " << endl;
      cout << MinNumebrMatrix(Matrix1 , 3, 3) << " ";



      cout << "\n The Max Number in Matrix is : " << endl;
      cout << MaxNumebrMatrix(Matrix1 , 3, 3) << " ";


      return 0;
}