#include <iostream>
using namespace std;


struct stTaskDuration
{
    int Days;
    int Hours;
    int Minutes;
    int Seconds;
};



stTaskDuration ReadTaskDuration()
{
    stTaskDuration Time;

    cout << "Enter Number of Days: ";
    cin >> Time.Days;

    cout << "Enter Number of Hours: ";
    cin >> Time.Hours;

    cout << "Enter Number of Minutes: ";
    cin >> Time.Minutes;

    cout << "Enter Number of Seconds: ";
    cin >> Time.Seconds;

    return Time;
}



int CalculateTotalSeconds(stTaskDuration Time)
{
    return (Time.Days * 24 * 60 * 60)
         + (Time.Hours * 60 * 60)
         + (Time.Minutes * 60)
         + Time.Seconds;
}


void PrintResult(int TotalSeconds)
{
    cout << "\nTotal Seconds = "
         << TotalSeconds
         << " Seconds"
         << endl;
}


int main()
{
    stTaskDuration Time = ReadTaskDuration();

    int TotalSeconds = CalculateTotalSeconds(Time);

    PrintResult(TotalSeconds);

    return 0;
}