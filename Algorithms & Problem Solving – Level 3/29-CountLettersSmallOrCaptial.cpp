#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string  ReadString()
{
      string S1;
      cout << "Please Enter Your String?\n";
      getline(cin, S1);
      return S1;
}

short CounterLettersUpper(string s1){

      short count = 0;

      for (int i = 0; i < s1.length(); i++)
      {
            if (isupper(s1[i]))
            {
                  count++;
            }
            
      }
      
      return count;
}


short CounterLetters(string s1){

      short count;

      for (int i = 0; i < s1.length(); i++)
      {
            if (!isupper(s1[i]))
            {
                  count++;
            }
            
      }
      
      return count;
}



int main()
{
      string S1 = ReadString();
      cout << "\nString after Inverting All Letters Case:\n";
      cout << CounterLettersUpper(S1);


      return 0;
}