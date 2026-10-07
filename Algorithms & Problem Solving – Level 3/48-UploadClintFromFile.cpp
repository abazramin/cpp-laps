#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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

vector<string> SplitString(string S1, string Delim)
{
      vector<string> vString;
      short pos = 0;
      string sWord;

      while ((pos = S1.find(Delim)) != std::string::npos)
      {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                  vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
      }
      if (S1 != "")
      {
            vString.push_back(S1);
      }
      return vString;
}

stClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
      stClient Client;
      vector<string> vClientData;

      vClientData = SplitString(Line, Seperator);
      Client.AccountNumber = vClientData[0];
      Client.PinCode = vClientData[1];
      Client.Name = vClientData[2];
      Client.Phone = vClientData[3];
      Client.AccountBalance = stod(vClientData[4]); // cast string to double

      return Client;
}

vector<stClient> UploadRecoredFromFiles(string FileName)
{
      vector<stClient> vClient;
      fstream MyFileName;

      MyFileName.open(FileName, ios::in);

      if (MyFileName.is_open())
      {
            string Line;
            stClient Client;
            while (getline(MyFileName, Line))
            {
                  Client = ConvertLinetoRecord(Line);
                  vClient.push_back(Client);
            }

            MyFileName.close();
      }

      return vClient;
}

void PrintClientRecord(stClient Client)
{

      cout << "\nAccout Number: " << Client.AccountNumber;
      cout << "\nPin Code : " << Client.PinCode;
      cout << "\nName : " << Client.Name;
      cout << "\nPhone : " << Client.Phone;
      cout << "\nAccount Balance: " << Client.AccountBalance;
}

void PrintAllClientsRecords(vector<stClient> vClinet)
{

      cout << "\n\nThe following is the extracted client record:\n";
      cout << "count is : " << vClinet.size() << endl;

      for (stClient record : vClinet)
      {
            PrintClientRecord(record);
            cout << endl;
      }
}

int main()
{

      vector<stClient> vClient = UploadRecoredFromFiles(ClientsFileName);

      PrintAllClientsRecords(vClient);
      return 0;
}