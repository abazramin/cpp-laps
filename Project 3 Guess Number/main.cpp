#include <iostream>
using namespace std;




struct stGameInfo
{
      int RandomNumber;
      // enRols TooLow = enRols::TooLow;
      // enRols TooHigh = enRols::TooLow;
      short UserInput;
      int TringCount;
};

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
        cout << Message  << " : ";  
        cin >> Number;
    } while (Number <= 0);  

    return Number;  
}


void PlayRound(){

      stGameInfo info;

      info.RandomNumber = RandomNumber(1,10) ;
      

      cout << "\n-------------------------------------"  << endl;
      cout << "\nComputer Genration Randdom Numbers :-) " << endl;
      cout << "\n----------Guess The Number ---------- " << endl;



      info.UserInput = ReadPositiveNumber("Guess The Number ??");

            while (info.RandomNumber != info.UserInput)
            {
                  info.TringCount++;
                  if (info.UserInput > info.RandomNumber)
                  {
                        cout << "Too High" << endl;
                        info.UserInput =  ReadPositiveNumber("Try Again!");
                  } else {
                        cout  << "Too Low" << endl;
                        info.UserInput =  ReadPositiveNumber("Try Again!");
                  }  
            }
            
          
            if (info.UserInput == info.RandomNumber)
            {
                  cout << "\nYou Matched ! , You Enterd " << info.UserInput << " and The Computer Enterd " << info.RandomNumber << " Your Winner Congreat ! " << endl; 
                  cout << "\n----------------------------------\n" ;
                  cout << "You Got It After " << info.TringCount << " Trying !" <<endl;
                   return;
            }


}


void PlayGame(){
      
      char PlayAgain = 'Y';

      do
      {
            PlayRound();

            cout << "\nDo you want to play again? (Y/N): ";
            cin >> PlayAgain;


      } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main(){
      srand((unsigned)time(NULL)); 

      PlayGame();

      return 0;
}