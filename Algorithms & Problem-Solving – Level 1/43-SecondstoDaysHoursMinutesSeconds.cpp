#include <iostream>
using namespace std;

struct stTaskDuration
{
    int Days;
    int Hours;
    int Minutes;
    int Seconds;
};

stTaskDuration ConvertSecondsToTime(int TotalSeconds)
{
    stTaskDuration Time;

    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHour = 60 * 60;
    const int SecondsPerMinute = 60;

    Time.Days = TotalSeconds / SecondsPerDay;

    int Reminder = TotalSeconds % SecondsPerDay;

    Time.Hours = Reminder / SecondsPerHour;

    Reminder = Reminder % SecondsPerHour;

    Time.Minutes = Reminder / SecondsPerMinute;

    Time.Seconds = Reminder % SecondsPerMinute;

    return Time;
}

void PrintResult(stTaskDuration Time)
{
    cout << "The Result is : "
         << Time.Days << " : "
         << Time.Hours << " : "
         << Time.Minutes << " : "
         << Time.Seconds
         << endl;
}

int main()
{
    int TotalSeconds;

    cout << "Enter Total Seconds: ";
    cin >> TotalSeconds;

    stTaskDuration Time = ConvertSecondsToTime(TotalSeconds);

    PrintResult(Time);

    return 0;
}