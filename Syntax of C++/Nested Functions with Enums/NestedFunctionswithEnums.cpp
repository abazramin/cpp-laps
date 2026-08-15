#include <iostream>
using namespace std;


enum enWeekOfDay{Monday = 1 ,Tuesday = 2, Wednesday = 3 , Thursday = 4 , Friday = 5, Saturday = 6, Sunday = 7};


void ShwoMenuOfDays(){

      cout << "Choose Days From 1 To 7 " << endl;

      cout << "* * * * * * * * * * * * * * * * * * * " << endl;
      cout << "Enter 1 for Monday" << endl;
      cout << "Enter 2 for Tuesday" << endl;
      cout << "Enter 3 for Wednesday" << endl;
      cout << "Enter 4 for Thursday" << endl;
      cout << "Enter 5 for Friday" << endl;
      cout << "Enter 6 for Saturday" << endl;
      cout << "Enter 7 for Sunday" << endl;
      cout << "* * * * * * * * * * * * * * * * * * * " << endl;

      cout << "Enter Your Day : " << endl;
}


enWeekOfDay ReadWeekOfDay(){

      int num;
      cin >> num;

      enWeekOfDay WD = (enWeekOfDay)num;
      return WD;
}



string DisplayDayOfWeek(enWeekOfDay ReadDay){
      switch (ReadDay)
      {
      case enWeekOfDay::Monday: 
            return "Monday";
            break;
      
      default:
      cout << "Invalid Numbers" << endl;
            break;
      }



      return "";
}


int main(){

      ShwoMenuOfDays();

      cout << DisplayDayOfWeek(ReadWeekOfDay());

      return 0;
}