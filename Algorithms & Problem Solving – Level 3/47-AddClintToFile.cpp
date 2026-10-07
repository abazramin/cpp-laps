#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
      string AccountNumber;
      string PinCode;
      string Name;
      string Phone;
      double AccountBalance;
};

stClient ReadNewClient()
{
      stClient Client;
      cout << "Enter Account Number? ";
      // Usage of std::ws will extract allthe whitespace character
      getline(cin >> ws, Client.AccountNumber);
      cout << "Enter PinCode? ";
      getline(cin, Client.PinCode);
      cout << "Enter Name? ";
      getline(cin, Client.Name);
      cout << "Enter Phone? ";
      getline(cin, Client.Phone);
      cout << "Enter AccountBalance? ";
      cin >> Client.AccountBalance;
      return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
      string stClientRecord = "";
      stClientRecord += Client.AccountNumber + Seperator;
      stClientRecord += Client.PinCode + Seperator;
      stClientRecord += Client.Name + Seperator;
      stClientRecord += Client.Phone + Seperator;
      stClientRecord += to_string(Client.AccountBalance);

      return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
      fstream MyFile;
      MyFile.open(FileName, ios::out | ios::app);
      if (MyFile.is_open())
      {
            MyFile << stDataLine << endl;
            MyFile.close();
      }
}

void AddNewClient()
{
      stClient Client;
      Client = ReadNewClient();
      AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
      char AddMore = 'Y';
      do
      {
            cout << "Adding New Client:\n\n";
            AddNewClient();
            cout << "\nClient Added Successfully, do you want to add more clients? Y / N?";
            cin >> AddMore;
      } while (toupper(AddMore) == 'Y');
}

int main()
{
      AddClients();

      return 0;
}