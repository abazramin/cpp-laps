#include <iostream>
#include <string>

using namespace std;



string ReadString()
{
      string s1;
      cout << "\nPlease Enter a String?\n";
      cin >> s1;
      return s1;
}

bool IsVowel(char Ch1)
{
      Ch1 = tolower(Ch1);
      return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

void PrintAllVowels(string S1)
{
      short Counter = 0;

      for (short i = 0; i < S1.length(); i++)
      {
            if (IsVowel(S1[i]))
                  cout << S1[i] << " ";
      }
}


int main(){


      string Ch1 = ReadString();



      cout << "All Vowel in Letters  is : " << endl;

      PrintAllVowels(Ch1);

      return 0;
}