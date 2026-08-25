#include <iostream>   
using namespace std;  

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message << endl;  
        cin >> Number;            
    } while (Number <= 0);        
    
    return Number;  
}

int RandomNumber(int From, int To)
{
   
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  


    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}


void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    
    cout << "\n";  
}


void SumOfTwoArray(int arr1[100] , int arr2[100] , int arr3[100] , int arrlenght){
    for (int i = 0; i < arrlenght; i++)
    {
        arr3[i] = arr2[i] + arr1[i];
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr1[100];
    int arr2[100];   
    int arr3[100];   

    int arrLength;  

    FillArrayWithRandomNumbers(arr1, arrLength);
    cout << "\nArray One Elements: ";
    PrintArray(arr1, arrLength);



    FillArrayWithRandomNumbers(arr2, arrLength);
    cout << "\nArray Two Elements: ";
    PrintArray(arr2, arrLength);


    SumOfTwoArray(arr1 , arr2 , arr3 , arrLength);
    cout << "\nArrays After Sum: ";
    PrintArray(arr3, arrLength);

    return 0;  
}