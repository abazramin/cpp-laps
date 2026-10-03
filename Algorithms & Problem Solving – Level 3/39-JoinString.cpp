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

int main()
{
      vector<string> S1 = {"Hello", "World", "from", "C++"};

      string joinedString = JoinString(S1, "-");

      cout << "Joined String: '" << joinedString << "'" << endl;
      return 0;
}
