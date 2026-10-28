#include <iostream>

using namespace std;

struct stDate
{
      short Year;
      short Month;
      short Day;
};

bool IsLastDayInMonth(stDate Date);

short DayOfWeekOrder(short Day, short Month, short Year)
{
      short a, y, m;
      a = (14 - Month) / 12;
      y = Year - a;
      m = Month + (12 * a) - 2;
      // Gregorian:
      // 0:sun, 1:Mon, 2:Tue...etc
      return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool IsLastMonthInYear(short Month)
{
      return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
      if (IsLastDayInMonth(Date))
      {
            if (IsLastMonthInYear(Date.Month))
            {
                  Date.Month = 1;
                  Date.Day = 1;
                  Date.Year++;
            }
            else
            {
                  Date.Day = 1;
                  Date.Month++;
            }
      }
      else
      {
            Date.Day++;
      }
      return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
      return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
      int Days = 0;
      while (IsDate1BeforeDate2(Date1, Date2))
      {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
      }
      return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(stDate Date)
{
      return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

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
short NumberOfDaysInAMonth(stDate Date)
{
      return NumberOfDaysInAMonth(Date.Month, Date.Year);
}
stDate GetSystemDate()
{
      stDate Date;
      time_t t = time(0);
      tm *now = localtime(&t);
      Date.Year = now->tm_year + 1900;
      Date.Month = now->tm_mon + 1;
      Date.Day = now->tm_mday;
      return Date;
}

string DayShortName(short DayOfWeekOrder)
{
      string arrDayNames[] = {
          "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
      return arrDayNames[DayOfWeekOrder];
}

bool isEndOfWeek(stDate Date)
{
      return DayOfWeekOrder(Date) == 6;
}

bool isWeekEnd(stDate Date)
{
      short index = DayOfWeekOrder(Date);

      return (index == 5 || index == 6);
}

bool isBusinessDay(stDate Date)
{
      return !isWeekEnd(Date);
}

bool IsLastDayInMonth(stDate Date)
{
      return (Date.Day == NumberOfDaysInAMonth(Date.Month,
                                               Date.Year));
}
short DaysUntilEndOfWeek(stDate Date)
{
      return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date1)
{
      stDate EndOfMontDate;
      EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
      EndOfMontDate.Month = Date1.Month;
      EndOfMontDate.Year = Date1.Year;
      return GetDifferenceInDays(Date1, EndOfMontDate, true);
}

short DaysUntilTheEndOfYear(stDate Date1)
{
      stDate EndOfYearDate;
      EndOfYearDate.Day = 31;
      EndOfYearDate.Month = 12;
      EndOfYearDate.Year = Date1.Year;
      return GetDifferenceInDays(Date1, EndOfYearDate, true);
}

int main()
{

      stDate Date = GetSystemDate();
      cout << "Today is : " << DayShortName(DayOfWeekOrder(Date)) << " ";
      cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

      if (isEndOfWeek(Date))
            cout << "Yes , its  end of week" << endl;
      else
            cout << "no ! is f " << DayShortName(DayOfWeekOrder(Date)) << " not end of week " << endl;

      if (isWeekEnd(Date))
            cout << "Yes , its  weekend" << endl;
      else
            cout << "no ! is  " << DayShortName(DayOfWeekOrder(Date)) << " not  of weekend " << endl;

      if (isBusinessDay(Date))
            cout << "Yes , its  Businss Day" << endl;
      else
            cout << "no ! is  " << DayShortName(DayOfWeekOrder(Date)) << " not  of Businss day " << endl;

      cout << "Days until end of week : " << DaysUntilEndOfWeek(Date) << "Day(s)" << endl;
      cout << "\nDays until end of month : "
           << DaysUntilTheEndOfMonth(Date) << " Day(s).";
      //---------------------
      cout << "\nDays until end of year : "
           << DaysUntilTheEndOfYear(Date) << " Day(s).";
      return 0;
}