#include <iostream>
#include <string>
using namespace std;

enum enSelectLevel { Easy = 1, Medium = 2, Hard = 3 , Mix = 4};

enum enOperationType { Add = 1, Subtract = 2, Multiply = 3, Divide = 4 , Mix = 5};

struct stInfoGame
{
      int CountOfRound = 0;
      enSelectLevel ReadLevelFromUser;
      enOperationType ReadOp;
      int Number1 = 0;
      int Number2 = 0;
      int Result = 0;
};

struct stResultOfGame
{
      short NumberOfQuestions = 0;        
      enSelectLevel QuestionLevel;   
      enOperationType OpType;  
      short NumberRightAnswer = 0;
      short NumberWrongAnswer = 0;         
};

enOperationType ReadOpType()
{
    int OT = 0;  

    cout << "Please enter Operation Type [1] Add , [2] Sub , [3] Mul ,[4] Div , [5] Mix )?\n";
    cin >> OT;

    return (enOperationType)OT;
}

enSelectLevel ReadLevel()
{
    int Level = 0;  

    cout << "Please enter Level ( 1-Easy, 2-Medium, 3-Hard, 4-Mix )?\n";
    cin >> Level;

    return (enSelectLevel)Level;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
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

int SelectTypeLevel(enSelectLevel level){
      switch (level)
      {
      case enSelectLevel::Easy:
            return RandomNumber(1 , 10);
      case enSelectLevel::Medium:
            return RandomNumber(11 ,20);
      case enSelectLevel::Hard:
            return RandomNumber(21 , 30);
      case enSelectLevel::Mix:
            return RandomNumber(1,100);
      default:
            return 0;
      }
 }

enOperationType SelectRandomOpType(int Choice)
{
    switch (Choice)
    {
    case 1:
        return enOperationType::Add;
    case 2:
        return enOperationType::Subtract;
    case 3:
        return enOperationType::Multiply;
    case 4:
        return enOperationType::Divide;
    default:
        return enOperationType::Add;
    }
}

int Calculate(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;  
    case enOperationType::Subtract:
        return Number1 - Number2;  
    case enOperationType::Multiply:
        return Number1 * Number2;  
    case enOperationType::Divide:
        return Number1 / Number2;  
    default:
        return 0;  
    }
}

string OpName(enOperationType op){
      switch (op)
      {
      case enOperationType::Add:
            return "+";
      case enOperationType::Divide:
            return "/";
      case enOperationType::Subtract:
            return "-";
      case enOperationType::Multiply:
            return "*";
      default:
            return "";
      }
}

string LevelName(enSelectLevel Level)
{
    switch (Level)
    {
    case enSelectLevel::Easy:
        return "Easy";
    case enSelectLevel::Medium:
        return "Medium";
    case enSelectLevel::Hard:
        return "Hard";
    case enSelectLevel::Mix:
        return "Mix";
    default:
        return "Unknown";
    }
}

stResultOfGame PlayRounds(short HowManyRounds)
{
      stInfoGame info;

      short NumberRightAnswer = 0, NumberWrongAnswer = 0;

      info.ReadLevelFromUser = ReadLevel();
      info.ReadOp = SelectRandomOpType(ReadOpType());

      for (int RoundGame = 1; RoundGame <= HowManyRounds; RoundGame++)
      {
            info.CountOfRound = RoundGame;
            info.Number1 = SelectTypeLevel(info.ReadLevelFromUser);
            info.Number2 = SelectTypeLevel(info.ReadLevelFromUser);
            info.Result = Calculate(info.Number1, info.Number2, info.ReadOp);

            int PlayerAnswer = ReadPositiveNumber("What is the result of " + to_string(info.Number1) + " " + OpName(info.ReadOp) + " " + to_string(info.Number2) + "?");

            if (PlayerAnswer == info.Result)
                  NumberRightAnswer++;
            else
                  NumberWrongAnswer++;
      }

       return { HowManyRounds, info.ReadLevelFromUser, info.ReadOp, NumberRightAnswer, NumberWrongAnswer };
}

void PlayGame(){
      
      char PlayAgain = 'Y';

      do
      {
            stResultOfGame GameResults = PlayRounds(ReadPositiveNumber("How Many You Want To Play")); 

            cout << "\n The  Numebr of  Question : " << GameResults.NumberOfQuestions << endl;

            cout << "\n The  Level  Selected : " << 
            LevelName(GameResults.QuestionLevel) << endl;

            cout << "\n The  Operation Selected : " << 
            OpName(GameResults.OpType) << endl;
          
            cout << "\n The  Right Answer is  : " << GameResults.NumberRightAnswer << endl;

             cout << "\n The  Wrong Answer is  : " << GameResults.NumberWrongAnswer << endl;

            cout << "\nDo you want to play again? (Y/N): ";
            cin >> PlayAgain;

      } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main(){

      srand((unsigned)time(NULL));  

      PlayGame();

      return 0;
}