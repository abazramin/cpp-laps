#include <iostream>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

struct Counter
{
    int PlayerWins = 0;
    int ComputerWins = 0;
    int Draws = 0;
};


enum enPlayers { Player = 1 , Computer = 2 , Draw = 3};

enum  enRole { Stone = 1 , Paper = 2 , Scissor = 3 };

enRole ReadPlayerChoice()
{
    int Choice;

    cout << "Choose your choice:\n";
    cout << "1. Stone ";
    cout << "2. Paper ";
    cout << "3. Scissor ";
    cin >> Choice;

    return (enRole)Choice;
}

enRole GetComputerChoice()
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

void PrintWinner(Counter c)
{
    enPlayers Winner;

    switch (Winner)
    {
    case enPlayers::Player:
        cout << "Player Wins! " << c.PlayerWins << endl;
        break;

    case enPlayers::Computer:
        cout << "Computer Wins! " << c.ComputerWins << endl;
        break;

    case enPlayers::Draw:
        cout << "Draw! " << c.Draws  << endl;
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
// i take the lenght of game , that mean i will run game == length
void PlayRounds(int &lenght){

    Counter c;

    c.PlayerWins = 0;
    c.ComputerWins = 0;
    c.Draws = 0;

    

      for (int i = 0; i <= lenght - 1 ; i++)
      {
         enPlayers winner =  SelectWinner(ReadPlayerChoice() , GetComputerChoice());

         if (winner == enPlayers::Player)
         {
            c.PlayerWins++;
         } else if (winner == enPlayers::Computer){
            c.ComputerWins++;
         } else {
            c.Draws++;
         }
         
      }
      
      PrintWinner(c);
 }



void StartGame(){
      int lenght = ReadPositiveNumber("Enter How Many You Want to Play ");
      PlayRounds(lenght);
}

int main(){

    srand(time(0));

    StartGame();
}  