#include <iostream>
using namespace std;


enum enCountries {Egypt = 1, SaudiArabia = 2, UAE = 3, Kuwait = 4, Qatar = 5, Bahrain = 6, Oman = 7};


int main() {

      cout << "Enter your country code (1-7): \n";
      cout << "1: Egypt" << endl;
      cout << "2: Saudi Arabia" << endl;
      cout << "3: UAE" << endl;
      cout << "4: Kuwait" << endl;
      cout << "5: Qatar" << endl;
      cout << "6: Bahrain" << endl;
      cout << "7: Oman" << endl;
      
      int countryCode;
      cin >> countryCode;
      enCountries country = (enCountries)countryCode;

      if (country == Egypt) {
            cout << "You are from Egypt." << endl;
      } else if (country == SaudiArabia) {
            cout << "You are from Saudi Arabia." << endl;
      } else if (country == UAE) {
            cout << "You are from UAE." << endl;
      } else if (country == Kuwait) {
            cout << "You are from Kuwait." << endl;
      } else if (country == Qatar) {
            cout << "You are from Qatar." << endl;
      } else if (country == Bahrain) {
            cout << "You are from Bahrain." << endl;
      } else if (country == Oman) {
            cout << "You are from Oman." << endl;
       } else {
            cout << "Invalid country code." << endl;
      }

    return 0;
}