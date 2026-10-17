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
      if (year % 400 == 0)
      {
            return true;
      }
      else if (year % 100 == 0)
      {
            return false;
      }
      else if (year % 4 == 0)
      {
            return true;
      }
      else
      {
            return false;
      }
}

void RuninngCode()
{

      char tryAgain = 'y';

      do
      {
            short year = ReadYears("Enter The Year ?");

            if (isLeapYear(year))
            {
                  cout << "yes , [ " << year << " ] is leap Year";
            }
            else
            {
                  cout << "no , [ " << year << " ] is leap Year";
            }

            cout << "\ndo you wnat to try again ! [y]/[n] ? " << endl;
            cin >> tryAgain;

      } while (tryAgain == 'y' || tryAgain == 'Y');
}

int main()
{
      RuninngCode();

      return 0;
}