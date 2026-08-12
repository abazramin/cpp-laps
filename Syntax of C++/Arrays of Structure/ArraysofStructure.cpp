#include <iostream>
using namespace std;


struct PersonInformation
{
      /* data */
      string firstName;
      string lastName;
      short age;
      string phone;
};

void ReadingInfo(PersonInformation &person) {
     cout << "Reading InfoPerson..." << endl;

      cout << "Enter first name: " << endl;;
      cin >> person.firstName;
      cout << "Enter last name: " << endl;  
      cin >> person.lastName;
      cout << "Enter age: " << endl;
      cin >> person.age;
      cout << "Enter phone: " << endl;  
      cin >> person.phone;
}

void PrintInfo(PersonInformation person) {

      cout << "\n* * * * * * * * * * * * * *" << endl;
      cout << "First Name: " << person.firstName << endl;
      cout << "Last Name : " << person.lastName << endl;
      cout << "Age : " << person.age << endl;
      cout << "Phone : " << person.phone << endl;
      cout << "* * * * * * * * * * * * * *" << endl;
}

void ReadPersonsInfo(PersonInformation person[2]){
      ReadingInfo(person[0]);
      ReadingInfo(person[1]);
}

void PrintPersonsInfo(PersonInformation person[2]){
      PrintInfo(person[0]);
      PrintInfo(person[1]);
}

int main() {

      PersonInformation Person[2];
      ReadPersonsInfo(Person);
      PrintPersonsInfo(Person);

      return 0;
}
