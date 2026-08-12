#include <iostream>
using namespace std;


struct InfoPerson
{
      /* data */
      string name;
      int age;
      string country;
      string address;
};


void ResetInfo(InfoPerson &person) {
     cout << "Resetting InfoPerson..." << endl;

      cout << "Enter name: ";
      cin >> person.name;
      cout << "Enter age: ";  
      cin >> person.age;
      cout << "Enter country: ";  
      cin >> person.country;
      cout << "Enter address: ";  
      cin >> person.address;
}


void PrintInfo(InfoPerson &person) {

      cout << "* * * * * * * * * * * * * *" << endl;
      cout << "Name: " << person.name << endl;
      cout << "Age: " << person.age << endl;
      cout << "Country: " << person.country << endl;
      cout << "Address: " << person.address << endl;
      cout << "* * * * * * * * * * * * * *" << endl;
}

int main() {
    InfoPerson person;

    ResetInfo(person);
    PrintInfo(person);

    return 0;
}