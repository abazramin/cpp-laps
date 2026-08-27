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


int main(){

      int arr[100] , lenght;

      FillArray(arr , lenght);

      PrintArray(arr , lenght);

      
      return 0;
}