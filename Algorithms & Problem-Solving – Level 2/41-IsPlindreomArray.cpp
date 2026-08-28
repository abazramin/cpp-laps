#include <iostream>  
using namespace std; 


void FillArray(int arr[100], int &arrLength)
{
    arrLength = 5;  


    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 20;
    arr[4] = 10;
}

void PrintArray(int arr[100] , int Lenght){
      for (int i = 0; i < Lenght; i++)
            {
                  cout <<arr[i] << " ";
            }
        cout << endl;
      
}


bool CheckPlindromNumber(int arr[100] , int Length){
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] != arr[ Length - 1 - i])
            return false;
    }

    return true;  
}




int main(){

    int arr[100] , lenghtarr1;
    FillArray(arr , lenghtarr1);

    bool result = CheckPlindromNumber(arr , lenghtarr1);

    if (result)
    {
        PrintArray(arr , lenghtarr1);
        cout << "Yes , Array is Plindrom" << endl;
    } else {
        cout << "No ! , Array is't Plindrom" << endl;
        
    }

      return 0;
}


