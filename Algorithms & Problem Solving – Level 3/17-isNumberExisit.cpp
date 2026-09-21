
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

int ReadPositiveNumber()
{
    int number;

    cout << "Enter a positive number You Need to Search: ";
    cin >> number;

    while (number < 0)
    {
        cout << "Must enter a positive number: ";
        cin >> number;
    }

    return number;
}


int main()
{
      int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

      cout << "\nMatrix1:\n";
      PrintMatrix(Matrix1, 3, 3);

      
      int Number = ReadPositiveNumber();


      if (IsNumberExsist(Matrix1, Number , 3, 3))
            cout << "\nYes: It is Thier\n";
      else
            cout << "\nNo: It's NOT Thier\n";

      return 0;
}