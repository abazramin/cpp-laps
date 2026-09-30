#include <iostream>

using namespace std;

char ReadChar()
{
      char Ch1;
      cout << "\nPlease Enter a Character?\n";
      cin >> Ch1;
      return Ch1;
}

bool IsVowel(char Ch1)
{
      Ch1 = tolower(Ch1);
      return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

short CountVowels(string S1)
{
      short Counter = 0;

      for (short i = 0; i < S1.length(); i++)
      {
            if (IsVowel(S1[i]))
                  Counter++;
      }
      
      return Counter;
}

int main(){


      char Ch1 = ReadChar();

      if (IsVowel(Ch1))
            cout << "\nYES Letter \'" << Ch1 << "\' is vowel";
      else
            cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel";

      return 0;
}