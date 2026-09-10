#include <iostream>
using namespace std;

struct stEmplyee
{
      string Name;
      float Salary;
};

int main(){


      stEmplyee emp , *ptr;


      emp.Name = "omer";
      emp.Salary = 7500;

      cout << emp.Name << endl;
      cout << emp.Salary << endl;

      ptr = &emp;

      cout << "\nUsing Poniter " << endl;
      cout << ptr->Name << endl;
      cout << ptr->Salary << endl;;


      return 0;
}