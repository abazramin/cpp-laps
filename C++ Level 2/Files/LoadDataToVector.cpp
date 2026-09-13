#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void LoadDataToVectors(string FileName , vector<string> &vText)
{
      fstream MyFile;

      MyFile.open( FileName, ios::in ); //read Mode

      if (MyFile.is_open())
      {
            string Line;

      while (getline(MyFile, Line))
      {
            vText.push_back(Line);
      }
            MyFile.close();
      }
}



int main(){


      vector<string> vText;

      LoadDataToVectors("write.txt" , vText);

      for (string &text : vText)
      {
            cout << text << endl;
      }
      

      return 0;
}