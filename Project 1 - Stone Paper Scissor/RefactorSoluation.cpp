#include <iostream>
using namespace std;

enum enPlayers { Player = 1 , Computer = 2 , Draw = 3};

enum  enRole { Stone = 1 , Paper = 2 , Scissor = 3 };

struct stInfoGame
{
      int CountOfRound = 0;
      enRole ChoosePlayer;
      enRole ChooseComputer;
      enPlayers winner;
      string NameOfWinner;

};

struct stGameResults
{
    short GameRounds = 0;        
    short Player1WinTimes = 0;   
    short ComputerWinTimes = 0;  
    short DrawTimes = 0;        
    enPlayers GameWinner;         
    string WinnerName = "";      
};

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

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

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

enPlayers WhoWonTheRound(stInfoGame RoundInfo)
{

    if (RoundInfo.ChoosePlayer == RoundInfo.ChooseComputer)
        return enPlayers::Draw;

    // Determine the winner based on game rules.
    switch (RoundInfo.ChoosePlayer)
    {
    case enRole::Stone:
        return (RoundInfo.ChooseComputer == enRole::Paper) ? enPlayers::Computer : enPlayers::Player;
    case enRole::Paper:
        return (RoundInfo.ChooseComputer == enRole::Scissor) ? enPlayers::Computer : enPlayers::Player;
    case enRole::Scissor:
        return (RoundInfo.ChooseComputer == enRole::Stone) ? enPlayers::Computer : enPlayers::Player;
    }

    return enPlayers::Player;
}

string WinnerName(enPlayers Winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
    return arrWinnerName[Winner - 1];
}

string ChoiceName(enRole Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

void PrintRoundResults(stInfoGame info){
      cout << "\n____________ Round [" << info.CountOfRound << "] ____________\n\n";
      cout << "Player1 Choice: " << ChoiceName(info.ChoosePlayer) << endl;
      cout << "Computer Choice: " << ChoiceName(info.ChooseComputer) << endl;
      cout << "Round Winner   : [" << info.winner << "]\n";
      cout << "_________________________________________\n" << endl;
}

enPlayers WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes) return enPlayers::Player;
    else if (ComputerWinTimes > Player1WinTimes) return enPlayers::Computer;
    else return enPlayers::Draw;
}

stGameResults PlayRounds(short HowManyRounds){
      
      stInfoGame info;
      short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

      for (int RoundGame = 1; RoundGame < HowManyRounds; RoundGame++)
      {
            info.CountOfRound = RoundGame;
            info.ChoosePlayer = ReadPlayerChoice();
            info.ChooseComputer = GetComputerChoice();
            info.winner =  WhoWonTheRound(info);
            info.NameOfWinner = WinnerName(info.winner);
      


      if (info.winner == enPlayers::Player)
            Player1WinTimes++;
        else if (info.winner == enPlayers::Computer) {
            ComputerWinTimes++;
        }
        else {
            DrawTimes++;
      }
            PrintRoundResults(info);
      }


       return { HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes, WhoWonTheGame(Player1WinTimes, ComputerWinTimes), WinnerName(WhoWonTheGame(Player1WinTimes, ComputerWinTimes)) };
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");  
        stGameResults GameResults = PlayRounds(ReadPositiveNumber("How Many You Want To Play")); 
        cout << "\nGame Over! Winner: " << GameResults.WinnerName << endl;

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));  
    StartGame();  
    return 0;  
}