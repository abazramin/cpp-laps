#include <iostream>
#include <cstdlib>

using namespace std;

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

void ShowAllClientsScreen()
{
      cout << "\n";
      cout << "========================================\n";
      cout << "             CLIENT LIST\n";
      cout << "========================================\n\n";

      cout << "Client List (" << 0 << ") Client(s).\n";
      cout << "----------------------------------------\n";

      cout << "| Account Number | Client Name | Balance |\n";
      cout << "----------------------------------------\n";

      cout << "No clients available.\n";

      cout << "----------------------------------------\n";
      cout << "\nPress any key to return to Main Menu...";
}

void HandlingSystems(enOpType OT)
{

      switch (OT)
      {
      case enOpType::ShowAll:
            ClearScreen();
            ShowAllClientsScreen();
            break;

      default:
            break;
      }
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
      cout << "[6]  Transactions\n";
      cout << "[7]  Exit\n\n";

      cout << "Choose what do you want to do? [1 - 7]: ";
      HandlingSystems(ReadOpType());
}

int main()
{

      HomeScreenPage();
      return 0;
}