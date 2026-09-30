#include <iostream>
#include <string>

using namespace std;


void PrintEachString(string S1)
{
      string delim = " "; 
      cout << "\nYour string wrords are: \n\n";

      short counter = 0;
      short pos = 0;
      string sWord; 

      while ((pos = S1.find(delim)) != std::string::npos)
      {
            sWord = S1.substr(0, pos); 
            if (sWord != "")
            {
                  counter++;
            }

            S1.erase(0, pos + delim.length());

      }

      if (S1 != "")
      {
            counter++;
      }
      cout << "\nTotal number of words: " << counter << endl;
}



string ReadString()
{
      string S1;
      cout << "\nPlease Enter a String?\n";
      cin.ignore();
      getline(cin, S1);
      return S1;
}


int main(){


      PrintEachString(ReadString());


      return 0;
}