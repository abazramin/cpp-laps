#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

void login();
void ShowMainMenue();
void ShowManagerMenueUsers();
void ShowTransactionsMenue();

struct sClient
{
      string AccountNumber;
      string PinCode;
      string Name;
      string Phone;
      double AccountBalance;
      bool MarkForDelete = false;
};

struct stUsers
{
      string UserName;
      string Password;
      int Permissions;
      bool MarkForDelete = false;
};

enum enPermissions
{
      pAll = -1,
      pShowClients = 1,   // 00000001
      pAddClient = 2,     // 00000010
      pDeleteClient = 4,  // 00000100
      pUpdateClient = 8,  // 00001000
      pFindClient = 16,   // 00010000
      pTransactions = 32, // 00100000
      pManageUsers = 64   // 01000000
};

stUsers CurrentUser;

bool CheckAccessPermission(enPermissions Permission);

string ReadUserName()
{
      string Username = "";
      cout << "\nPlease enter Username? ";
      cin >> Username;
      return Username;
}

bool FindUserByUsername(string Username, vector<stUsers> vUsers,
                        stUsers &User)
{
      for (stUsers U : vUsers)
      {
            if (U.UserName == Username)
            {
                  User = U;
                  return true;
            }
      }
      return false;
}

int ReadPermissionsToSet()
{
      int Permissions = 0;
      char Answer = 'n';

      cout << "\nDo you want to give full access to this user? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
      {
            return -1;
      }

      cout << "\nDo you want to give access to Show Clients? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
            Permissions |= pShowClients;

      cout << "Do you want to give access to Add Client? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
            Permissions |= pAddClient;

      cout << "Do you want to give access to Delete Client? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
            Permissions |= pDeleteClient;

      cout << "Do you want to give access to Update Client? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
            Permissions |= pUpdateClient;

      cout << "Do you want to give access to Find Client? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
            Permissions |= pFindClient;

      cout << "Do you want to give access to Transaction Client? ";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
            Permissions |= pTransactions;

      return Permissions;
}

vector<string> SplitString(string S1, string Delim)
{

      vector<string> vString;

      size_t pos = 0;
      string sWord; // define a string variable

      // use find() function to get the position of the delimiters
      while ((pos = S1.find(Delim)) != std::string::npos)
      {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
                  vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
      }

      if (S1 != "")
      {
            vString.push_back(S1); // it adds last word of the string.
      }

      return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

      sClient Client;
      vector<string> vClientData;

      vClientData = SplitString(Line, Seperator);

      Client.AccountNumber = vClientData[0];
      Client.PinCode = vClientData[1];
      Client.Name = vClientData[2];
      Client.Phone = vClientData[3];
      Client.AccountBalance = stod(vClientData[4]); // cast string to double

      return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

      string stClientRecord = "";

      stClientRecord += Client.AccountNumber + Seperator;
      stClientRecord += Client.PinCode + Seperator;
      stClientRecord += Client.Name + Seperator;
      stClientRecord += Client.Phone + Seperator;
      stClientRecord += to_string(Client.AccountBalance);

      return stClientRecord;
}

stUsers ConvertUsertoRecord(string Line, string Seperator = "#//#")
{

      stUsers Users;
      vector<string> vClientData;

      vClientData = SplitString(Line, Seperator);

      Users.UserName = vClientData[0];
      Users.Password = vClientData[1];
      Users.Permissions = stoi(vClientData[2]); // cast string to double

      return Users;
}

string ConvertUserToLine(stUsers User, string Seperator = "#//#")
{

      string stUserRecord = "";

      stUserRecord += User.UserName + Seperator;
      stUserRecord += User.Password + Seperator;
      stUserRecord += to_string(User.Permissions);

      return stUserRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

      vector<sClient> vClients;

      fstream MyFile;
      MyFile.open(FileName, ios::in); // read Mode

      if (MyFile.is_open())
      {

            string Line;
            sClient Client;

            while (getline(MyFile, Line))
            {

                  Client = ConvertLinetoRecord(Line);
                  if (Client.AccountNumber == AccountNumber)
                  {
                        MyFile.close();
                        return true;
                  }

                  vClients.push_back(Client);
            }

            MyFile.close();
      }

      return false;
}

bool IsUserExistsByUserNameAndPassword(string UserName, string Password, stUsers &User)
{
      ifstream MyFile("Users.txt");

      if (!MyFile.is_open())
            return false;

      string Line;

      while (getline(MyFile, Line))
      {
            User = ConvertUsertoRecord(Line);

            if (User.UserName == UserName &&
                User.Password == Password)
            {
                  return true;
            }
      }

      return false;
}

sClient ReadNewClient()
{
      sClient Client;

      cout << "Enter Account Number? ";

      // Usage of std::ws will extract allthe whitespace character
      getline(cin >> ws, Client.AccountNumber);

      while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
      {
            cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
            getline(cin >> ws, Client.AccountNumber);
      }

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

vector<sClient> LoadCleintsDataFromFile(string FileName)
{

      vector<sClient> vClients;

      fstream MyFile;
      MyFile.open(FileName, ios::in); // read Mode

      if (MyFile.is_open())
      {

            string Line;
            sClient Client;

            while (getline(MyFile, Line))
            {

                  Client = ConvertLinetoRecord(Line);

                  vClients.push_back(Client);
            }

            MyFile.close();
      }

      return vClients;
}

vector<stUsers> LoadUsersDataFromFile()
{

      vector<stUsers> vUsers;

      fstream MyFile;
      MyFile.open("Users.txt", ios::in); // read Mode

      if (MyFile.is_open())
      {

            string Line;
            stUsers Users;

            while (getline(MyFile, Line))
            {

                  Users = ConvertUsertoRecord(Line);

                  vUsers.push_back(Users);
            }

            MyFile.close();
      }

      return vUsers;
}

void PrintClientRecordLine(sClient Client)
{

      cout << "| " << setw(15) << left << Client.AccountNumber;
      cout << "| " << setw(10) << left << Client.PinCode;
      cout << "| " << setw(40) << left << Client.Name;
      cout << "| " << setw(12) << left << Client.Phone;
      cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientRecordLine(stUsers User)
{

      cout << "| " << setw(15) << left << User.UserName;
      cout << "| " << setw(10) << left << User.Password;
      cout << "| " << setw(40) << left << User.Permissions;
}

void PrintClientRecordBalanceLine(sClient Client)
{

      cout << "| " << setw(15) << left << Client.AccountNumber;
      cout << "| " << setw(40) << left << Client.Name;
      cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAccessDeniedMessage()
{
      cout << "\n------------------------------------\n";
      cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
      cout << "\n------------------------------------\n";
}

void ShowAllClientsScreen()
{

      if (!CheckAccessPermission(enPermissions::pShowClients))
      {
            ShowAccessDeniedMessage();
            return;
      }

      vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

      cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;

      cout << "| " << left << setw(15) << "Accout Number";
      cout << "| " << left << setw(10) << "Pin Code";
      cout << "| " << left << setw(40) << "Client Name";
      cout << "| " << left << setw(12) << "Phone";
      cout << "| " << left << setw(12) << "Balance";
      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;

      if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
      else

            for (sClient Client : vClients)
            {

                  PrintClientRecordLine(Client);
                  cout << endl;
            }

      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;
}

void ShowAllUsersScreen()
{

      if (!CheckAccessPermission(enPermissions::pManageUsers))
      {
            ShowAccessDeniedMessage();
            return;
      }

      vector<stUsers> vUsers = LoadUsersDataFromFile();

      cout << "\n\t\t\t\t Users List (" << vUsers.size() << ") User(s).";
      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;

      cout << "| " << left << setw(15) << "User Name";
      cout << "| " << left << setw(10) << "Password";
      cout << "| " << left << setw(40) << "Permissions";

      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;

      if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
      else

            for (stUsers User : vUsers)
            {

                  PrintClientRecordLine(User);
                  cout << endl;
            }

      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;
}

void ShowTotalBalances()
{

      vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

      cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;

      cout << "| " << left << setw(15) << "Accout Number";
      cout << "| " << left << setw(40) << "Client Name";
      cout << "| " << left << setw(12) << "Balance";
      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;

      double TotalBalances = 0;

      if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
      else

            for (sClient Client : vClients)
            {

                  PrintClientRecordBalanceLine(Client);
                  TotalBalances += Client.AccountBalance;

                  cout << endl;
            }

      cout << "\n_______________________________________________________";
      cout << "_________________________________________\n"
           << endl;
      cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
}

void PrintClientCard(sClient Client)
{
      cout << "\nThe following are the client details:\n";
      cout << "-----------------------------------";
      cout << "\nAccout Number: " << Client.AccountNumber;
      cout << "\nPin Code     : " << Client.PinCode;
      cout << "\nName         : " << Client.Name;
      cout << "\nPhone        : " << Client.Phone;
      cout << "\nAccount Balance: " << Client.AccountBalance;
      cout << "\n-----------------------------------\n";
}

void PrintUserCard(stUsers User)
{
      cout << "\nThe following are the Users details:\n";
      cout << "-----------------------------------";
      cout << "\nAccout Number: " << User.UserName;
      cout << "\nPin Code     : " << User.Password;
      cout << "\nName         : " << User.Permissions;
      cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
{

      for (sClient C : vClients)
      {

            if (C.AccountNumber == AccountNumber)
            {
                  Client = C;
                  return true;
            }
      }
      return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
      sClient Client;

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

stUsers ChangeUserRecord(string Username)
{
      stUsers User;
      User.UserName = Username;
      cout << "\n\nEnter Password? ";
      getline(cin >> ws, User.Password);
      User.Permissions = ReadPermissionsToSet();
      return User;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{

      for (sClient &C : vClients)
      {

            if (C.AccountNumber == AccountNumber)
            {
                  C.MarkForDelete = true;
                  return true;
            }
      }

      return false;
}

bool MarkUserForDeleteByUsername(string Username, vector<stUsers> &
                                                      vUsers)
{
      for (stUsers &U : vUsers)
      {
            if (U.UserName == Username)
            {
                  U.MarkForDelete = true;
                  return true;
            }
      }
      return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{

      fstream MyFile;
      MyFile.open(FileName, ios::out); // overwrite

      string DataLine;

      if (MyFile.is_open())
      {

            for (sClient C : vClients)
            {

                  if (C.MarkForDelete == false)
                  {
                        // we only write records that are not marked for delete.
                        DataLine = ConvertRecordToLine(C);
                        MyFile << DataLine << endl;
                  }
            }

            MyFile.close();
      }

      return vClients;
}

vector<stUsers> SaveUsersDataToFile(string FileName, vector<stUsers> vUsers)
{
      fstream MyFile;
      MyFile.open(FileName, ios::out); // overwrite
      string DataLine;
      if (MyFile.is_open())
      {
            for (stUsers U : vUsers)
            {
                  if (U.MarkForDelete == false)
                  {
                        // we only write records that are not marked for delete.
                        DataLine = ConvertUserToLine(U);
                        MyFile << DataLine << endl;
                  }
            }
            MyFile.close();
      }
      return vUsers;
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

void AddUserLineToFile(string stUser)
{
      fstream MyFile;
      MyFile.open("Users.txt", ios::out | ios::app);

      if (MyFile.is_open())
      {

            MyFile << stUser << endl;

            MyFile.close();
      }
}

void AddNewClient()
{
      sClient Client;
      Client = ReadNewClient();
      AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
      char AddMore = 'Y';
      do
      {
            // system("cls");
            cout << "Adding New Client:\n\n";

            AddNewClient();
            cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";

            cin >> AddMore;

      } while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{

      sClient Client;
      char Answer = 'n';

      if (FindClientByAccountNumber(AccountNumber, vClients, Client))
      {

            PrintClientCard(Client);

            cout << "\n\nAre you sure you want delete this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                  MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
                  SaveCleintsDataToFile(ClientsFileName, vClients);

                  // Refresh Clients
                  vClients = LoadCleintsDataFromFile(ClientsFileName);

                  cout << "\n\nClient Deleted Successfully.";
                  return true;
            }
      }
      else
      {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
      }

      return false;
}

bool DeleteUserByUsername(string Username, vector<stUsers> &
                                               vUsers)
{
      if (Username == "Admin")
      {
            cout << "\n\nYou cannot Delete This User.";
            return false;
      }
      stUsers User;
      char Answer = 'n';
      if (FindUserByUsername(Username, vUsers, User))
      {
            PrintUserCard(User);
            cout << "\n\nAre you sure you want delete this User? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                  MarkUserForDeleteByUsername(Username, vUsers);
                  SaveUsersDataToFile("Users", vUsers);
                  // Refresh Clients
                  vUsers = LoadUsersDataFromFile();
                  cout << "\n\nUser Deleted Successfully.";
                  return true;
            }
      }
      else
      {
            cout << "\nUser with Username (" << Username << ") is Not Found!";
            return false;
      }

      return false;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{

      sClient Client;
      char Answer = 'n';

      if (FindClientByAccountNumber(AccountNumber, vClients, Client))
      {

            PrintClientCard(Client);
            cout << "\n\nAre you sure you want update this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {

                  for (sClient &C : vClients)
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
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
      }

      return false;
}

bool UpdateUserByUsername(string Username, vector<stUsers> &
                                               vUsers)
{
      stUsers User;
      char Answer = 'n';
      if (FindUserByUsername(Username, vUsers, User))
      {
            PrintUserCard(User);
            cout << "\n\nAre you sure you want update this User? y/n ?";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                  for (stUsers &U : vUsers)
                  {
                        if (U.UserName == Username)
                        {
                              U = ChangeUserRecord(Username);
                              break;
                        }
                  }
                  SaveUsersDataToFile("Users.txt", vUsers);
                  cout << "\n\nUser Updated Successfully.";
                  return true;
            }
      }
      else
      {
            cout << "\nUser with Account Number (" << Username << ") is Not Found!";
            return false;
      }

      return false;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> &vClients)
{

      char Answer = 'n';

      cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
      cin >> Answer;
      if (Answer == 'y' || Answer == 'Y')
      {

            for (sClient &C : vClients)
            {
                  if (C.AccountNumber == AccountNumber)
                  {
                        C.AccountBalance += Amount;
                        SaveCleintsDataToFile(ClientsFileName, vClients);
                        cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                        return true;
                  }
            }

            return false;
      }

      return false;
}

string ReadClientAccountNumber()
{
      string AccountNumber = "";

      cout << "\nPlease enter AccountNumber? ";
      cin >> AccountNumber;
      return AccountNumber;
}

void ShowDeleteClientScreen()
{
      if (!CheckAccessPermission(enPermissions::pDeleteClient))
      {
            ShowAccessDeniedMessage();
            return;
      }

      cout << "\n-----------------------------------\n";
      cout << "\tDelete Client Screen";
      cout << "\n-----------------------------------\n";

      vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
      string AccountNumber = ReadClientAccountNumber();
      DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowDeleteUserScreen()
{
      cout << "\n-----------------------------------\n";
      cout << "\tDelete Users Screen";
      cout << "\n-----------------------------------\n";
      vector<stUsers> vUsers = LoadUsersDataFromFile();
      string Username = ReadUserName();
      DeleteUserByUsername(Username, vUsers);
}

void ShowUpdateUserScreen()
{
      cout << "\n-----------------------------------\n";
      cout << "\tUpdate Users Screen";
      cout << "\n-----------------------------------\n";
      vector<stUsers> vUsers = LoadUsersDataFromFile();
      string Username = ReadUserName();
      UpdateUserByUsername(Username, vUsers);
}

void ShowUpdateClientScreen()
{
      if (!CheckAccessPermission(enPermissions::pUpdateClient))
      {
            ShowAccessDeniedMessage();
            return;
      }
      cout << "\n-----------------------------------\n";
      cout << "\tUpdate Client Info Screen";
      cout << "\n-----------------------------------\n";

      vector<sClient> vClients =
          LoadCleintsDataFromFile(ClientsFileName);
      string AccountNumber = ReadClientAccountNumber();
      UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindUserScreen()
{
      cout << "\n-----------------------------------\n";
      cout << "\tFind User Screen";
      cout << "\n-----------------------------------\n";
      vector<stUsers> vUsers = LoadUsersDataFromFile();
      stUsers User;
      string Username = ReadUserName();
      if (FindUserByUsername(Username, vUsers, User))
            PrintUserCard(User);
      else
            cout << "\nUser with Username [" << Username << "] is not found!";
}

void ShowFindClientScreen()
{
      if (!CheckAccessPermission(enPermissions::pFindClient))
      {
            ShowAccessDeniedMessage();
            return;
      }
      cout << "\n-----------------------------------\n";
      cout << "\tFind Client Screen";
      cout << "\n-----------------------------------\n";
      vector<sClient> vClients =
          LoadCleintsDataFromFile(ClientsFileName);
      sClient Client;
      string AccountNumber = ReadClientAccountNumber();
      if (FindClientByAccountNumber(AccountNumber, vClients,
                                    Client))
            PrintClientCard(Client);
      else
            cout << "\nClient with Account Number[" << AccountNumber
                 << "] is not found!";
}

void ShowAddNewClientsScreen()
{
      if (!CheckAccessPermission(enPermissions::pAddClient))
      {
            ShowAccessDeniedMessage();
            return;
      }

      cout << "\n-----------------------------------\n";
      cout << "\tAdd New Clients Screen";
      cout << "\n-----------------------------------\n";

      AddNewClients();
}

void ShowEndScreen()
{
      cout << "\n-----------------------------------\n";
      cout << "\tProgram Ends :-)";
      cout << "\n-----------------------------------\n";
}

void ShowDepositScreen()
{
      cout << "\n-----------------------------------\n";
      cout << "\tDeposit Screen";
      cout << "\n-----------------------------------\n";

      sClient Client;

      vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
      string AccountNumber = ReadClientAccountNumber();

      while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
      {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = ReadClientAccountNumber();
      }

      PrintClientCard(Client);

      double Amount = 0;
      cout << "\nPlease enter deposit amount? ";
      cin >> Amount;

      DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithDrawScreen()
{
      cout << "\n-----------------------------------\n";
      cout << "\tWithdraw Screen";
      cout << "\n-----------------------------------\n";

      sClient Client;

      vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
      string AccountNumber = ReadClientAccountNumber();

      while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
      {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = ReadClientAccountNumber();
      }

      PrintClientCard(Client);

      double Amount = 0;
      cout << "\nPlease enter withdraw amount? ";
      cin >> Amount;

      // Validate that the amount does not exceeds the balance
      while (Amount > Client.AccountBalance)
      {
            cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
            cout << "Please enter another amount? ";
            cin >> Amount;
      }

      DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void ShowTotalBalancesScreen()
{

      ShowTotalBalances();
}

enum enTransactionsMenueOptions
{
      eDeposit = 1,
      eWithdraw = 2,
      eShowTotalBalance = 3,
      eShowMainMenue = 4
};

enum enMainMenueOptions
{
      eListClients = 1,
      eAddNewClient = 2,
      eDeleteClient = 3,
      eUpdateClient = 4,
      eFindClient = 5,
      eShowTransactionsMenue = 6,
      eManagerUsers = 7,
      eExit = 8
};

enum enManageUserOption
{
      eListUsers = 1,
      eAddUser = 2,
      eDeleteUser = 3,
      eUpdateUser = 4,
      eFindUSer = 5,
      eMainMenu = 6
};

bool UserExistsByUsername(string Username, string FileName)
{
      fstream MyFile;
      MyFile.open(FileName, ios::in); // read Mode
      if (MyFile.is_open())
      {
            string Line;
            stUsers User;
            while (getline(MyFile, Line))
            {
                  User = ConvertUsertoRecord(Line);
                  if (User.UserName == Username)
                  {
                        MyFile.close();
                        return true;
                  }
            }
            MyFile.close();
      }
      return false;
}

stUsers ReadNewUser()
{
      stUsers User;

      cout << "\nEnter User Name? ";
      getline(cin >> ws, User.UserName);

      while (UserExistsByUsername(User.UserName, "Users.txt"))
      {

            cout << "\n User Name is already exists [ " << User.UserName << " ] Enter User Name ? ";
            getline(cin >> ws, User.UserName);
      }

      cout << "\nEnter Password? ";
      getline(cin, User.Password);

      cout << endl;
      User.Permissions = ReadPermissionsToSet();

      return User;
}

void AddNewUser()
{
      stUsers User;
      User = ReadNewUser();
      AddUserLineToFile(ConvertUserToLine(User));
}

void AddNewUsers()
{
      char AddMore = 'Y';
      do
      {
            system("cls");
            cout << "Adding New User:\n\n";

            AddNewUser();
            cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";

            cin >> AddMore;

      } while (toupper(AddMore) == 'Y');
}

bool CheckAccessPermission(enPermissions Permission)
{
      if (CurrentUser.Permissions == enPermissions::pAll)
            return true;

      if ((Permission & CurrentUser.Permissions) == Permission)
            return true;
      else
            return false;
}

void GoBackToMainMenue()
{
      cout << "\n\nPress any key to go back to Main Menue...";
      system("pause>0");
      ShowMainMenue();
}

void GoBackToTransactionsMenue()
{
      cout << "\n\nPress any key to go back to Transactions Menue...";
      system("pause>0");
      ShowTransactionsMenue();
}

void GoBackToManagrUserScreen()
{
      cout << "\n\nPress any key to go back to Main Menue...";
      system("pause>0");
      ShowManagerMenueUsers();
}

short ReadTransactionsMenueOption()
{
      cout << "Choose what do you want to do? [1 to 4]? ";
      short Choice = 0;
      cin >> Choice;

      return Choice;
}

short ReadMainMenueOption()
{
      cout << "Choose what do you want to do? [1 to 8]? ";
      short Choice = 0;
      cin >> Choice;

      return Choice;
}

short ReadUserMenueOption()
{
      cout << "Choose what do you want to do? [1 to 6]? ";
      short Choice = 0;
      cin >> Choice;

      return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
      switch (TransactionMenueOption)
      {
      case enTransactionsMenueOptions::eDeposit:
      {
            system("cls");
            ShowDepositScreen();
            GoBackToTransactionsMenue();
            break;
      }

      case enTransactionsMenueOptions::eWithdraw:
      {
            system("cls");
            ShowWithDrawScreen();
            GoBackToTransactionsMenue();
            break;
      }

      case enTransactionsMenueOptions::eShowTotalBalance:
      {
            system("cls");
            ShowTotalBalancesScreen();
            GoBackToTransactionsMenue();
            break;
      }

      case enTransactionsMenueOptions::eShowMainMenue:
      {

            ShowMainMenue();
      }
      }
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{

      switch (MainMenueOption)
      {
      case enMainMenueOptions::eListClients:
            system("cls");
            ShowAllClientsScreen();
            GoBackToMainMenue();
            break;

      case enMainMenueOptions::eAddNewClient:
            system("cls");
            ShowAddNewClientsScreen();
            GoBackToMainMenue();
            break;

      case enMainMenueOptions::eDeleteClient:
            system("cls");
            ShowDeleteClientScreen();
            GoBackToMainMenue();
            break;

      case enMainMenueOptions::eUpdateClient:
            system("cls");
            ShowUpdateClientScreen();
            GoBackToMainMenue();
            break;

      case enMainMenueOptions::eFindClient:
            system("cls");
            ShowFindClientScreen();
            GoBackToMainMenue();
            break;

      case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            ShowTransactionsMenue();
            break;
      case enMainMenueOptions::eManagerUsers:
            system("cls");
            ShowManagerMenueUsers();
            break;
      case enMainMenueOptions::eExit:
            system("cls");
            login();
            break;
      }
}

void PerfromUsersMenueOption(enManageUserOption ManageUser)
{
      switch (ManageUser)
      {
      case enManageUserOption::eListUsers:
      {
            system("cls");
            ShowAllUsersScreen();
            GoBackToManagrUserScreen();
            break;
      }
      case enManageUserOption::eAddUser:
            system("cls");
            AddNewUsers();
            GoBackToManagrUserScreen();
            break;

      case enManageUserOption::eDeleteUser:
            system("cls");
            ShowDeleteUserScreen();
            GoBackToManagrUserScreen();
            break;

      case enManageUserOption::eUpdateUser:
            system("cls");
            ShowUpdateUserScreen();
            GoBackToManagrUserScreen();
            break;

      case enManageUserOption::eFindUSer:
            system("cls");
            ShowFindUserScreen();
            GoBackToManagrUserScreen();
            break;

      case enManageUserOption::eMainMenu:
            system("cls");
            ShowMainMenue();
            break;
      }
}

void ShowMainMenue()
{
      system("cls");
      cout << "===========================================\n";
      cout << "\t\tMain Menue Screen\n";
      cout << "===========================================\n";
      cout << "\t[1] Show Client List.\n";
      cout << "\t[2] Add New Client.\n";
      cout << "\t[3] Delete Client.\n";
      cout << "\t[4] Update Client Info.\n";
      cout << "\t[5] Find Client.\n";
      cout << "\t[6] Transactions.\n";
      cout << "\t[7] Manager Users.\n";
      cout << "\t[8] Logout.\n";
      cout << "===========================================\n";
      PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

void ShowTransactionsMenue()
{
      system("cls");
      cout << "===========================================\n";
      cout << "\t\tTransactions Menue Screen\n";
      cout << "===========================================\n";
      cout << "\t[1] Deposit.\n";
      cout << "\t[2] Withdraw.\n";
      cout << "\t[3] Total Balances.\n";
      cout << "\t[4] Main Menue.\n";
      cout << "===========================================\n";
      PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

void ShowManagerMenueUsers()
{

      if (!CheckAccessPermission(enPermissions::pManageUsers))
      {
            ShowAccessDeniedMessage();
            return;
      }

      system("cls");
      cout << "===========================================\n";
      cout << "\t\tManage Users Menue Screen\n";
      cout << "===========================================\n";
      cout << "\t[1] List Users.\n";
      cout << "\t[2] Add New User.\n";
      cout << "\t[3] Delete User.\n";
      cout << "\t[4] Update User Info.\n";
      cout << "\t[5] Find User.\n";
      cout << "\t[6] Main Menu.\n";
      cout << "===========================================\n";
      PerfromUsersMenueOption((enManageUserOption)ReadUserMenueOption());
}

void login()
{
      bool LoginFailed = false;
      string UserName, Password;
      do
      {
            system("cls");

            cout << "===========================================\n";
            cout << "\t\tLogin Screen\n";
            cout << "===========================================\n";

            cout << "Enter The User Name: ";
            getline(cin >> ws, UserName);

            cout << "Enter The Password: ";
            getline(cin, Password);

            LoginFailed = !IsUserExistsByUserNameAndPassword(UserName, Password, CurrentUser);

            if (LoginFailed)
            {
                  cout << "\nInvalid username or password!\n";
                  system("pause");
            }

      } while (LoginFailed);

      ShowMainMenue();
}

int main()
{
      login();

      return 0;
}