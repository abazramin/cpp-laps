#include <iostream>
#include <string>
using namespace std;



enum enPlayers { Player = 1 , Computer = 2 , Draw = 3};

enum  enRole { Stone = 1 , Paper = 2 , Scissor = 3 };

enRole ReadPlayerChoice()
{
    int Choice;

    cout << "Choose your choice:\n";
    cout << "1. Stone\n";
    cout << "2. Paper\n";
    cout << "3. Scissor\n";
    cin >> Choice;

    return (enRole)Choice;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

enRole ComputerChoice()
{
    int Choice = RandomNumber(1,3);

    return (enRole)Choice;
}

enPlayers SelectWinner(enRole PlayerChoice, enRole ComputerChoice)
{
    switch (PlayerChoice)
    {
    case enRole::Stone:

        if (ComputerChoice == enRole::Scissor)
            return enPlayers::Player;

        if (ComputerChoice == enRole::Paper)
            return enPlayers::Computer;

        break;


    case enRole::Paper:

        if (ComputerChoice == enRole::Stone)
            return enPlayers::Player;

        if (ComputerChoice == enRole::Scissor)
            return enPlayers::Computer;

        break;


    case enRole::Scissor:

        if (ComputerChoice == enRole::Paper)
            return enPlayers::Player;

        if (ComputerChoice == enRole::Stone)
            return enPlayers::Computer;

        break;
    }

    return enPlayers::Draw;
}

enRole GetComputerChoice()
{
    int Choice = RandomNumber(1,3);

    return (enRole)Choice;
}

void PrintWinner(enPlayers Winner)
{
    switch (Winner)
    {
    case enPlayers::Player:
        cout << "Player Wins!" << endl;
        break;

    case enPlayers::Computer:
        cout << "Computer Wins!" << endl;
        break;

    case enPlayers::Draw:
        cout << "Draw!" << endl;
        break;
    }
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message << endl;  
        cin >> Number;  
    } while (Number <= 0);  

    return Number;  
}

void ReadCountOfRound(int arr[100] , int &lenght){


      for (int i = 0; i <= lenght - 1 ; i++)
      {
            ReadPlayerChoice();
      }
      
 }

void PrintArrayData(int arr[100] , int lenght){

      for (int i = 0; i < lenght; i++)
      {
            /* code */
            cout << "Number is " << i + 1 << " = " << arr[i] << endl;
      }
      
 }


int main(){

      srand(time(0));

      int round[100];
      int lenght = ReadPositiveNumber("Enter How Many You Want to Play ");

      ReadCountOfRound(round , lenght);
}