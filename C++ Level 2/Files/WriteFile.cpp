#include <iostream>
#include <fstream>

using namespace std;


int main(){

      fstream MyFile;

      MyFile.open("write.txt" , ios::out); // write mode;


      if (MyFile.is_open())
      {
         
            MyFile << "Hello And Welcome To The Fisrt Write in My Mac os\n";
            MyFile.close();
      }

      return 0;
}