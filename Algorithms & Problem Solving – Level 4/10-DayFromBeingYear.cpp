#include <iostream>

using namespace std;

bool isLeapYear(short Year)
{
      return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
      if (Month < 1 || Month > 12)
            return 0;
      int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short GetDayOrder(short Day, short Month, short Year)
{
      short total = 0;

      for (short i = 1; i < Month; i++)
      {
            total += NumberOfDaysInAMonth(i, Year);
      }

      total += Day;

      return total;
}

short ReadMonth()
{
      short Month;
      cout << "\nPlease enter a Month to check? ";
      cin >> Month;
      return Month;
}
short ReadYear()
{
      short Year;
      cout << "\nPlease enter a year to check? ";
      cin >> Year;
      return Year;
}

short ReadDay()
{
      short Day;
      cout << "\nPlease enter a Day? ";
      cin >> Day;
      return Day;
}

int main()
{
      short Day = ReadDay();
      short Month = ReadMonth();
      short Year = ReadYear();
      cout << "\nDate :" << Day << "/" << Month << "/" << Year;
      cout << "\nDay Order : " << GetDayOrder(Day, Month, Year);

      return 0;
}