#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
      string S1;

      cout << "Please Enter Your String?\n";

      getline(cin, S1);

      return S1;
}

char ReadChar()
{
      char Ch1;
      cout << "Please Enter a Character?\n";
      cin >> Ch1;
      return Ch1;
}

short CounterLetters(string s1 , char target){

      short count = 0;

      for (int i = 0; i < s1.length(); i++)
      {
            if (s1[i] == target)
            {
                  count++;
            }
      }
      
      return count;
}

int main()
{

      string s1 = ReadString();


      char Ch1 = ReadChar();

      cout << "The Letters count is : " << CounterLetters(s1 , Ch1); 

      
      return 0;
}
