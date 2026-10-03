#include <iostream>
#include <vector>
#include <string>

using namespace std;

string TirmLeft(string S1)
{
      size_t pos = S1.find_first_not_of(" \t\n\r\f\v");

      if (pos != string::npos)
      {
            return S1.substr(pos);
      }

      return "";
}

string TrimLeft(string S1)
{
      for (short i = 0; i < S1.length(); i++)
      {
            if (S1[i] != ' ')
            {
                  return S1.substr(i, S1.length() - i);
            }
      }
      return "";
}

string TirmRight(string S1)
{

      for (size_t i = S1.length() - 1; i > 0; i--)
      {
            if (S1[i] != ' ')
            {
                  return S1.substr(0, i + 1);
            }
      }
      return "";
}

int main()
{
      string S1 = "   Hello, World!";
      string trimmedString = TirmLeft(S1);

      cout << "Original String: '" << S1 << "'" << endl;
      cout << "Trimmed String: '" << trimmedString << "'" << endl;

      string S2 = "Hello, World!    ";
      string trimmedString2 = TirmRight(S2);

      cout << "Original String: '" << S2 << "'" << endl;
      cout << "Trimmed String: '" << trimmedString2 << "'" << endl;

      return 0;
}