#include <iostream>
using namespace std;





void PrintYourName(string name){
      cout << "Your Name is : " << name << endl;
}

void ReadYourName(){
      cout << "What's Your Name ?" <<endl;
      string name;
      cin >> name;


      PrintYourName(name);
}


int main(){
      ReadYourName();
}

