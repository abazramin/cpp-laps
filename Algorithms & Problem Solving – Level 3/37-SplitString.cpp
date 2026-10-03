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
    string Vword;

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

int main()
{
    vector<string> vSplting = SplitString(ReadString(), " ");

    cout << "Split size : " << vSplting.size() << endl;

    for (const string& s : vSplting)
    {
        cout << s << endl;
    }

    return 0;
}