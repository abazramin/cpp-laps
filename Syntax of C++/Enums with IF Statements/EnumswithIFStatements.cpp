#include <iostream>
using namespace std;


enum enCountries {Egypt = 1, SaudiArabia = 2, UAE = 3, Kuwait = 4, Qatar = 5, Bahrain = 6, Oman = 7};



void printCountry(){
      cout << "Enter your country code (1-7): \n";
      cout << "1: Egypt" << endl;
      cout << "2: Saudi Arabia" << endl;
      cout << "3: UAE" << endl;
      cout << "4: Kuwait" << endl;
      cout << "5: Qatar" << endl;
      cout << "6: Bahrain" << endl;
      cout << "7: Oman" << endl;
}

int main() {

      printCountry();
      
      int countryCode;
      cin >> countryCode;
      enCountries country = (enCountries)countryCode;

      switch (country)
      {
      case enCountries::Egypt:
            /* code */
            cout << "Yore are from Egypt." << endl;
            break;
      case enCountries::SaudiArabia:
            /* code */
            cout << "Yore are from Saudi Arabia." << endl;
            break;
      case enCountries::UAE:
            /* code */
            cout << "Yore are from UAE." << endl;
            break;
      case enCountries::Kuwait:
            /* code */
            cout << "Yore are from Kuwait." << endl;
            break;
      case enCountries::Qatar:            
            /* code */
            cout << "Yore are from Qatar." << endl;
            break;
      case enCountries::Bahrain:
            /* code */
            cout << "Yore are from Bahrain." << endl;
            break;
      case enCountries::Oman:
            /* code */
            cout << "Yore are from Oman." << endl;
            break;
      default:
            cout << "Invalid country code." << endl;
            break;
      }



    return 0;
}