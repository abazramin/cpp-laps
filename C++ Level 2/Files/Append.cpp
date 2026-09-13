#include <iostream>
#include <fstream>

using namespace std;


int main(){

      fstream MyFile;

      MyFile.open("append.txt" , ios::out || ios::app); // apend or write


      if (MyFile.is_open())
      {
            MyFile << "I am Happy to learing Files in c++" << endl;

            MyFile.close();
            
            cout << "Successed" << endl;
      } else {


            cout << "Filed" << endl;
      }
      

      return 0;
}