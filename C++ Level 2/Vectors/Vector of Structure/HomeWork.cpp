
#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
      string FirstName;
      string LastName;
      float Salary;
};



void  ReadEmployee(vector<stEmployee> &emp){
      bool AddMore;
      stEmployee employees;

      do
      {
            cout << "Enter The First Name" << endl;
            cin >> employees.FirstName;

            cout << "Enter The Last Name" << endl;
            cin >> employees.LastName;


            cout << "Enter The Salary" << endl;
            cin >> employees.Salary;


            emp.push_back(employees);

            cout << "Do You Wand Add More Employees :[1]Yes , [0]No ? " << endl;
            cin >> AddMore;

      } while (AddMore);
      
}



void PrintEmployess(vector<stEmployee> &vNumber){

      cout << "\n ----------------------------------- " << endl;

      cout << "The Print Of Employees is :  " << endl;

       for (stEmployee &emp : vNumber) {

            cout << "\n ----------------------------------- " << endl;
            cout << emp.FirstName << endl;
            cout << emp.LastName << endl;
            cout << emp.Salary << endl;
            
      }
}


int main(){


      vector<stEmployee> emp;

      ReadEmployee(emp);

      PrintEmployess(emp);

      return 0;
}