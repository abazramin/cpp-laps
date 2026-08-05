#include <iostream>
using namespace std;


int main(){

      string yourname;
      int age;
      bool ismearid;
      // Taking input from user
      cout << "Enter The Name" << endl;
      cin >> yourname;
      cout << "Enter your Age" << endl;
      cin >> age;
      cout << "Are you a mechatronics engineer? (1 for yes, 0 for no)" << endl;
      cin >> ismearid;
      // Displaying the name and age
      cout << "your Name is "<< yourname << " and your Age is " << age << " and your mechatronics engineer status is " << ismearid << endl;


      return 0;
}