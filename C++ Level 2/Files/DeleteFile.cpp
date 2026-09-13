#include <iostream>
#include <vector>
#include <fstream>

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

void SaveVectorToFile(string FileName, vector<string> vFileContent)
{
      fstream MyFile;
      MyFile.open("write.txt", ios::out);
      if (MyFile.is_open())
      {
            for (string &Line : vFileContent)
            {
                  if (Line != "")
                  {
                        MyFile << Line << endl;
                  }
            }

            MyFile.close();
      }
}

void PrintFileContenet(string FileName)
{
      fstream MyFile;

      MyFile.open( FileName, ios::in ); //read Mode

      if (MyFile.is_open())
      {
            string Line;
      while (getline(MyFile, Line))
      {
            cout << Line << endl;
      }
            MyFile.close();
      }
}

void DeleteRecordFromFile(string FileName, string Record)
{
      vector<string> vFileContent;
      LoadDataToVectors(FileName, vFileContent);

      for (string &Line : vFileContent)
      {
            if (Line == Record)
            {
                  Line = "";
            }
      }

      SaveVectorToFile(FileName, vFileContent);
}


int main(){

      cout << "befour delete" << endl;
      PrintFileContenet("write.txt");

      DeleteRecordFromFile("write.txt" , "Hello");

      cout << "after delete" << endl;
      PrintFileContenet("write.txt");

      return 0;
}