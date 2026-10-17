#include <iostream>

using namespace std;

short ReadYears(string message)
{

      short year;
      cout << message << endl;
      cin >> year;

      return year;
}

bool isLeapYear(short year)
{
      if (year % 400 == 0 && year % 100 != 0 || year % 4 == 0)
            return true;
}

short NumberOfDaysInAYear(short Year)
{
      return isLeapYear(Year) ? 366 : 365;
}
short NumberOfHoursInAYear(short Year)
{
      return NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
      return NumberOfHoursInAYear(Year) * 60;
}
int NumberOfSecondsInAYear(short Year)
{
      return NumberOfMinutesInAYear(Year) * 60;
}

int main()
{
      short Year = ReadYears("Enter a Year");
      cout << "\nNumber of Days in Year [" << Year << "] is "
           << NumberOfDaysInAYear(Year);
      cout << "\nNumber of Hours in Year [" << Year << "] is "
           << NumberOfHoursInAYear(Year);
      cout << "\nNumber of Minutes in Year [" << Year << "] is "
           << NumberOfMinutesInAYear(Year);
      cout << "\nNumber of Seconds in Year [" << Year << "] is "
           << NumberOfSecondsInAYear(Year);

      return 0;
}