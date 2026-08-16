#include <iostream>
#include <string>
using namespace std;



// we solve the number one and two in same file because they are very simple and easy to understand

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

