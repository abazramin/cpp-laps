#include <iostream>
using namespace std;


struct InfoPerson
{
      /* data */
      string name;
      int age;
      string city;
      string country;
      string address;
      char gender;
      bool isMarried;
};


void ResetInfo(InfoPerson &person) {
     cout << "Resetting InfoPerson..." << endl;

      cout << "Enter name: ";
      cin >> person.name;
      cout << "Enter age: ";  
      cin >> person.age;
      cout << "Enter city: ";
      cin >> person.city;
      cout << "Enter country: ";  
      cin >> person.country;
      cout << "Enter address: ";  
      cin >> person.address;
      cout << "Enter gender (M/F): ";  
      cin >> person.gender;
      cout << "Enter marital status (true/false): ";  
      cin >> person.isMarried;
}


void PrintInfo(InfoPerson &person) {

      cout << "\n* * * * * * * * * * * * * *" << endl;
      cout << "Name: " << person.name << endl;
      cout << "Age: " << person.age << endl;
      cout << "Country: " << person.country << endl;
      cout << "Address: " << person.address << endl;
      cout << "City: " << person.city << endl;  
      cout << "Gender: " << (person.gender == 'M' ? 'M' : 'F') << endl;
      cout << "Married: " << (person.isMarried ? "Yes" : "No") << endl;
      cout << "* * * * * * * * * * * * * *" << endl;
}

int main() {
      InfoPerson person;

      ResetInfo(person);
      PrintInfo(person);


      InfoPerson person2;
      ResetInfo(person2);     
      PrintInfo(person2);


      InfoPerson Person3;
      ResetInfo(Person3);
      PrintInfo(Person3);

    return 0;
}