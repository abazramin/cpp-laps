#include <iostream>
using namespace std;

void HasDriveLicenens(){
      short Age;
      bool HasDriveLicences;
      //
      cout << "Enter Your Age" << endl;
      cin >> Age;
      //
      cout << "Do You Have a Drive Licences ? Enter 1 if You Have it , And 0 if you did't" << endl;
      cin >> HasDriveLicences;
      //
      if (Age >= 21 && HasDriveLicences == true)
      {
           cout << "Hire" << endl;
      } else {
           cout << "Rejected !" << endl;

      }
}

bool isHasDriveLicenens(){
      short Age;
      bool HasDriveLicences;
      //
      cout << "Enter Your Age" << endl;
      cin >> Age;
      //
      cout << "Do You Have a Drive Licences ? Enter 1 if You Have it , And 0 if you did't" << endl;
      cin >> HasDriveLicences;
      //
      if (Age >= 21 && HasDriveLicences == true)
      {
           return true;
      } 

      return false;
}

bool isHasDriveLicenens(int Age , bool HasDriveLicences){
      if (Age >= 21 && HasDriveLicences == true)
      {
           return true;
      } 

      return false;
}


int main(){

      // HasDriveLicenens();

      // if (isHasDriveLicenens())
      // {
      //       /* code */
      //       cout << "Hire" << endl;
      // } else{
      //       cout << "Rejected!" << endl;

      // }
      
      int age;
      bool isHasDriveLicences;

      cout << "Enter The Age : " << endl;
      cin >> age;

      cout << "Enter 1 if you have D.L else Enter 0 : " << endl;
      cin >> isHasDriveLicences;


      bool res = isHasDriveLicenens(age , isHasDriveLicences);
      
     if (res)
     {
      /* code */
      cout << "Yes Youe Hier " << endl;
     } else {
      cout << "No !, Your Rejected" << endl;
     }
     
      return 0;
}