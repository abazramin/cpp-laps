#include <iostream>   
#include <string>     
#include <cstdlib>    
#include <ctime>      

using namespace std; 



int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

enum enCharType { 
    SamallLetter = 1,    
    CapitalLetter = 2,   
    SpecialCharacter = 3,
    Digit = 4           
};

char GetRandomCharacter(enCharType CharType)
{

    switch (CharType)
    {
    case enCharType::SamallLetter:
      {
             return char(RandomNumber(97, 122));
      }
    case enCharType::CapitalLetter:
      {
            return char(RandomNumber(65, 90));
      }
    case enCharType::SpecialCharacter:
      {
            return char(RandomNumber(33, 47));
      }
    case enCharType::Digit:
      {
            return char(RandomNumber(48, 57));
      }
    }
  
    return '\0';
}

string GenerateWord(enCharType TypeChar , short lenght){

      string word = "";
      for(int i = 0; i < lenght; i++){
            word = word + GetRandomCharacter(TypeChar);
      }

      return word;
}


string GenerateKey(){

       string Key = "";

       Key = Key + GenerateWord(enCharType::CapitalLetter , 4) + " - " ;
       Key = Key + GenerateWord(enCharType::CapitalLetter , 4) + " - " ;
       Key = Key + GenerateWord(enCharType::CapitalLetter , 4) + " - " ;
       Key = Key + GenerateWord(enCharType::CapitalLetter , 4) ;

       return Key;
}

void GenerateKeys(short count){

      for(int i = 1; i <= count; i++){
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
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


int main(){

      GenerateKeys(ReadPositiveNumber("Enter Number Count : "));

      return 0;
}