#include <iostream>
#include <string>

using namespace std;

string JoinString(const vector<string> S1, string Delimiter)
{
      string result = "";

      for (const string &s : S1)
      {
            result += s + Delimiter;
      }

      if (!result.empty())
      {
            result.erase(result.length() - Delimiter.length());
      }

      return result;
}

string JoinString(string arrString[], short lenght, string Delimiter)
{
      string result = "";

      for (int i = 0; i < lenght; i++)
      {
            result += arrString[i] + Delimiter;
      }

      if (!result.empty())
      {
            result.erase(result.length() - Delimiter.length());
      }

      return result;
}

int main()
{
      vector<string> S1 = {"Hello", "World", "from", "C++"};

      string joinedString = JoinString(S1, "-");

      cout << "Joined String: '" << joinedString << "'" << endl;

      string arrString[] = {"Hello", "World", "from", "C++"};

      string joinedString2 = JoinString(arrString, 4, "-");
      cout << "Joined String: '" << joinedString2 << "'" << endl;
      return 0;
}
