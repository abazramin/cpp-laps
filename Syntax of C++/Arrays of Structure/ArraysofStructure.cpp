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
     cout << "Reading InfoPerson...  " << endl;

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

void ReadPersonsInfo(PersonInformation person[100] , int &lenght){


      cout << "how person you have , you need count " << endl;
      cin >> lenght;


      for (int i = 0; i <= lenght - 1; i++)
      {
            /* code */
            cout << "Plase Enter Person's" << i + 1 << endl; 
            ReadingInfo(person[i]);
      }
      


      
}

void PrintPersonsInfo(PersonInformation person[100] , int lenght){
       for (int i = 0; i <= lenght - 1; i++)
      {
            /* code */
            cout << "Print Info of Person's" << i + 1 << endl; 
            PrintInfo(person[i]);
      }
}

int main() {

      PersonInformation Person[100];
      int lenght;


      


      ReadPersonsInfo(Person , lenght);
      PrintPersonsInfo(Person , lenght);

      return 0;
}
