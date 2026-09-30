#include <iostream>
#include <string>

using namespace std;



string ReadString()
{
      string Ch1;
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


      string Ch1 = ReadString();

      if (CountVowels(Ch1))
            cout << "\nYES Letter \'" << Ch1 << "\' is vowel";
      else
            cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel";
            


      cout << "Counter is : " << CountVowels(Ch1) << " " ;

      return 0;
}