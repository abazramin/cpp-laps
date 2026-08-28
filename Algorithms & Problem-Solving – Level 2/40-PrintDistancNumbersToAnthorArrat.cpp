#include <iostream>  
using namespace std; 


void FillArray(int arr[100], int &arrLength)
{
    arrLength = 10;  
    
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}


void PrintArray(int arr[100] , int Lenght){
      for (int i = 0; i < Lenght; i++)
            {
                  cout <<arr[i] << endl;
            }
      
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;  
    }

    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arrLength++;             
    arr[arrLength - 1] = Number;  
}


void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

int main(){

      int arr[100] , lenghtarr1;
      int arr2[100] , lengtharr2 = 0;
      FillArray(arr , lenghtarr1);

      PrintArray(arr , lenghtarr1);


      CopyDistinctNumbersToArray(arr , arr2 , lenghtarr1 , lengtharr2);



      PrintArray(arr2 , lengtharr2);

      return 0;
}


