#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ClearScreen()
{
      system("clear");
}

enum enOpType
{
      ShowAll = 1,
      AddNew = 2,
      Update = 3,
      Delete = 4,
      Find = 5,
      Exit = 6
};

enOpType ReadOpType()
{

      int OT = 0;

      cin >> OT;

      return (enOpType)OT;
}

struct stClient
{
      string AccountNumber;
      string PinCode;
      string Name;
      string Phone;
      double AccountBalance;
      bool MarkForDelete = false;
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
void DeleteClient()
{
      vector<stClient> vClients = UploadRecoredFromFiles(ClientsFileName);
      string AccountNumber = ReadCleintAccountNumber();
      DeleteClientByAccountNumber(AccountNumber, vClients);
}

stClient ChangeClientRecord(string AccountNumber)
{
      stClient Client;
      Client.AccountNumber = AccountNumber;
      cout << "\n\nEnter PinCode? ";
      getline(cin >> ws, Client.PinCode);
      cout << "Enter Name? ";
      getline(cin, Client.Name);
      cout << "Enter Phone? ";
      getline(cin, Client.Phone);
      cout << "Enter AccountBalance? ";
      cin >> Client.AccountBalance;

      return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
      stClient Client;
      char Answer = 'n';
      if (FindClientByAccountNumber(AccountNumber, vClients,
                                    Client))
      {
            PrintClientRecord(Client);
            cout << "\n\nAre you sure you want update this client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                  for (stClient &C : vClients)
                  {
                        if (C.AccountNumber == AccountNumber)
                        {
                              C = ChangeClientRecord(AccountNumber);
                              break;
                        }
                  }
                  SaveCleintsDataToFile(ClientsFileName, vClients);
                  cout << "\n\nClient Updated Successfully.";
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

void UpdateClient()
{
      vector<stClient> vClients = UploadRecoredFromFiles(ClientsFileName);
      string AccountNumber = ReadCleintAccountNumber();

      UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowAllClientsScreen()
{
      vector<stClient> vClient = UploadRecoredFromFiles(ClientsFileName);

      cout << "\n";
      cout << "========================================\n";
      cout << "             CLIENT LIST\n";
      cout << "========================================\n\n";

      cout << "Client List (" << vClient.size() << ") Client(s).\n";
      cout << "----------------------------------------\n";

      cout << "| Account Number | Client Name | Balance |\n";
      cout << "----------------------------------------\n";

      PrintAllClientsRecords(vClient);
}

void HomeScreenPage()
{
      cout << "========================================\n";
      cout << "       BANK MANAGEMENT SYSTEM\n";
      cout << "           Main Menu - v1.0\n";
      cout << "========================================\n\n";

      cout << "[1]  Show Client List\n";
      cout << "[2]  Add New Client\n";
      cout << "[3]  Delete Client\n";
      cout << "[4]  Update Client Info\n";
      cout << "[5]  Find Client\n";
      cout << "[6]  Exit\n\n";

      cout << "Choose what do you want to do? [1 - 6]: ";
}

void ExitOut()
{
      system("exit");
}

void HandlingSystems(enOpType OT)
{

      switch (OT)
      {
      case enOpType::ShowAll:
            ShowAllClientsScreen();
            break;
      case enOpType::AddNew:
            AddClients();
            break;
      case enOpType::Update:
            UpdateClient();
            break;
      case enOpType::Delete:
            DeleteClient();
            break;
      case enOpType::Find:
            // pending . . .
            break;
      case enOpType::Exit:
            ExitOut();
            break;
      default:
            break;
      }
}

int main()
{

      HomeScreenPage();

      enOpType ot = ReadOpType();

      HandlingSystems(ot);

      return 0;
}