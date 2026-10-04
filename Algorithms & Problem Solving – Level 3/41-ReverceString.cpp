#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadString()
{
    string S1;

    cout << "\nPlease Enter a String?\n";
    getline(cin, S1);

    return S1;
}

vector<string> SplitString(string S1, string Delim)
{
    size_t pos = 0;
    string Vword = "";

    vector<string> Vwords;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        Vword = S1.substr(0, pos);

        if (!Vword.empty())
        {
            Vwords.push_back(Vword);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (!S1.empty())
    {
        Vwords.push_back(S1);
    }

    return Vwords;
}

string ReverceString(string S1)
{
    vector<string> vString;
    string S2 = " ";

    vString = SplitString(S1, " ");

    vector<string>::iterator itre = vString.end();

    while (itre != vString.begin())
    {
        --itre;
        S2 += *itre + " ";
    }

    S2 = S2.substr(0, S2.length() - 1); // remove last space.

    return S2;
}

int main()
{
    string S1 = ReadString();
    cout << "\n\nString after reversing words:";
    cout << "\n"
         << ReverceString(S1);

    return 0;
}