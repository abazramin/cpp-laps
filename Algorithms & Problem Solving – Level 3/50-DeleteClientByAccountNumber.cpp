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
      bool MarkForDelete;
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

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClients, stClient &Client)
{
      for (stClient C : vClients)
      {
            if (C.AccountNumber == AccountNumber)
            {
                  Client = C;
                  return true;
            }
      }
      return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
      for (stClient &C : vClients)
      {
            if (C.AccountNumber == AccountNumber)
            {
                  C.MarkForDelete = true;
                  return true;
            }
      }
      return false;
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

vector<stClient> SaveCleintsDataToFile(string FileName, vector<stClient> vClients)
{
      fstream MyFile;
      MyFile.open(FileName, ios::out); // overwrite
      string DataLine;
      if (MyFile.is_open())
      {
            for (stClient C : vClients)
            {
                  if (C.MarkForDelete == false)
                  {
                        // we only write records that are not marked for delete
                        DataLine = ConvertRecordToLine(C);
                        MyFile << DataLine << endl;
                  }
            }
            MyFile.close();
      }
      return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
      stClient Client;
      char Answer = 'n';
      if (FindClientByAccountNumber(AccountNumber, vClients, Client))
      {
            PrintClientRecord(Client);
            cout << "\n\nAre you sure you want delete this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                  MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
                  SaveCleintsDataToFile(ClientsFileName, vClients);
                  // Refresh Clients
                  vClients = UploadRecoredFromFiles(ClientsFileName);
                  cout << "\n\nClient Deleted Successfully.";
                  return true;
            }
      }
      else
      {
            cout << "\nClient with Account Number (" << AccountNumber
                 << ") is Not Found!";
            return false;
      }
}

string ReadCleintAccountNumber()
{
      string AccountNumber;
      cout << "\nPlease enter the client account number: ";
      cin >> AccountNumber;
      return AccountNumber;
}

int main()
{
      vector<stClient> vClients = UploadRecoredFromFiles(ClientsFileName);
      string AccountNumber = ReadCleintAccountNumber();
      DeleteClientByAccountNumber(AccountNumber, vClients);

      return 0;
}