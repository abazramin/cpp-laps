#include <iostream>
using namespace std;

enum enGender {Male , Female};

int main() {

      struct Roles
      {
            /* data */
            string RolesName;
      };
      


       struct ContactInformation{
            string Phone;
            string Adress;
            string Email;
            Roles Roles;
        };

    struct PersonInformation {
        string name;
        int age;
        string city;
        string country;
        short MonthlySalary;
        int YearlySalary;
        char Gender;
        bool isMeried;
        ContactInformation contact;
       
    };

    PersonInformation person1;

    person1.name = "khalid";
    person1.age = 23;
    person1.city = "al baha";
    person1.country = "sudan";
    person1.MonthlySalary = 5600;
    person1.YearlySalary = 5600 * 12;
    person1.Gender = enGender::Male;
    person1.isMeried = false; 
    person1.contact.Phone = "01111111111";
    person1.contact.Adress = "al baha";
    person1.contact.Email = "asaf@gmail.com";
    person1.contact.Roles.RolesName = "Admin";


    // printing
    cout << "Name : " << person1.name << endl;
    cout <<  "Age : "<<person1.age << endl;
    cout << "City : "<<person1.city << endl;
    cout << "Coujntry : "<<person1.country << endl;
    cout << "Monthly Salary : "<<person1.MonthlySalary << endl;
    cout << "Yearly Salary : " <<person1.YearlySalary << endl;
    cout << "Gender : "<<person1.Gender << endl;
    cout << "is Meried : "<<person1.isMeried << endl;
    cout << "Phone Number : "<<person1.contact.Phone << endl;
      cout << "Address : "<<person1.contact.Adress << endl;
      cout << "His Email : "<<person1.contact.Email << endl;
      cout << "His Roles : " <<person1.contact.Roles.RolesName << endl;
    return 0;
}