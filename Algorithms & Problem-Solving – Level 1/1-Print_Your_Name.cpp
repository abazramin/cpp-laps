#include <iostream>
#include <string>
using namespace std;





void PrintYourName(string name){
      cout << "Your Name is : " << name << endl;
}

string ReadYourName(){

      cout << "What's Your Name ?" <<endl;
      string name;
      getline(cin , name);
      return name;
}


int main(){

      PrintYourName(ReadYourName());
}

