#include <iostream>
using namespace std;



struct stFullName
{
      /* data */
      string FirstName;
      string LastName;
};


stFullName ReadInfo(){
      stFullName info;

      cout << "Enter Your First Name " << endl;
      cin >> info.FirstName;

      cout << "Enter Your Last Name " << endl;
      cin >> info.LastName;

      return info;
}


string GetFullName(stFullName info , bool isReversed){
      if (isReversed)
            return info.LastName +" " + info.FirstName;
       else 
            return info.FirstName + " " + info.LastName;
}

void PrintFullName(string FullName){
      cout << "Your Name is : " << FullName << endl;
}


int main(){

      PrintFullName(GetFullName(ReadInfo() , 1));

      return 0;
}