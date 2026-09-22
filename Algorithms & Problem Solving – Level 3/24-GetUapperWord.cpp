#include <iostream>
#include <string>
using namespace std;


string ReadString()
{
      string S1;
      cout << "Please Enter Your String?\n";
      getline(cin, S1);
      return S1;
}

void GetFristLetters(string words){


      cout << words[0] << " ";

      for (int i = 0; i < words.length(); i++)
      {
            if (words[i] == ' ')
            {
                  cout << words[i + 1] << " ";
            }
            
      }
      
}

string PrintFirstLetterOfEachWordToUppper(string S1)
{
      bool isFirstLetter = true;

      cout << "\nFirst letters of this string: \n";
      for (short i = 0; i < S1.length(); i++)
      {
            if (S1[i] != ' ' && isFirstLetter)
            {
                        S1[i] = toupper(S1[i]);
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
      }

      return S1;
}

int main(){

      // GetFristLetters("Hello And Welecome To My Stirng");

      cout << PrintFirstLetterOfEachWordToUppper(ReadString()) << " ";

      return 0;
}