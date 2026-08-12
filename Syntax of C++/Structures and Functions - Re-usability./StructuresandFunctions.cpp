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


void ReadingInfo(InfoPerson &person) {
     cout << "Reading InfoPerson..." << endl;

      cout << "Enter name: " << endl;;
      cin >> person.name;
      cout << "Enter age: " << endl;  
      cin >> person.age;
      cout << "Enter city: " << endl;
      cin >> person.city;
      cout << "Enter country: " << endl;  
      cin >> person.country;
      cout << "Enter address: "<< endl;  
      cin >> person.address;
      cout << "Enter gender (M/F): "<< endl;  
      cin >> person.gender;
      cout << "Enter marital status (true/false): ";  
      cin >> person.isMarried;
}


void PrintInfo(InfoPerson person) {

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

      ReadingInfo(person);
      PrintInfo(person);
    return 0;
}