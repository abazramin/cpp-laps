#include <iostream>
using namespace std;


void ReadArrayData(int arr[100] , int &lenght){

      cout << "Enter Lenght The If You Want : " << endl;
      cin >> lenght;

      for (int i = 0; i <= lenght - 1 ; i++)
      {
            /* code */
            cout << "Enter Number " << i + 1 << endl;
            cin >> arr[i];
      }
      
 }

 void PrintArrayData(int arr[100] , int lenght){

      for (int i = 0; i < lenght; i++)
      {
            /* code */
            cout << "Number is " << i + 1 << " = " << arr[i] << endl;
      }
      
 }

int CalculateNumber(int arr[100] , int lenght){
      int sum = 0;

      for (int i = 0; i < lenght; i++)
      {
            /* code */
            sum += arr[i];
      }

      return sum;
      
}

float CalculateAvg(int arr[100] , int lenght){
      return (float)CalculateNumber(arr , lenght) / lenght;
}


 int main(){

      int arr1[100] , lenght;

      ReadArrayData(arr1 , lenght);
      PrintArrayData(arr1 , lenght);

      cout << "the sum for numbers is " << CalculateNumber(arr1 , lenght) << endl;
      cout << "the avg for numbers is " << CalculateAvg(arr1 , lenght) << endl;

 }