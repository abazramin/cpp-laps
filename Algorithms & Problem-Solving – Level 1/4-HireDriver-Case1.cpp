#include <iostream>
using namespace std;



struct  stPersonInfo
{
      int Age;
      bool HasDriveLicences;
      bool HasRecomminding;
};


stPersonInfo ReadInfo(){

      stPersonInfo info;


      cout << "Enter Your Age ? " << endl;
      cin >> info.Age;

      cout << "Enter If Yo Have Drive Licences" << endl;
      cin >> info.HasDriveLicences;

      cout << "Are You Have Any Recomminding > " << endl;
      cin >> info.HasRecomminding;


      return info;
}

bool isAccepted(stPersonInfo info){

      if (info.HasRecomminding)
      {
            return true;
      } else {
            return (info.Age >= 21 && info.HasDriveLicences == true);
      }
}


void PrintResult(stPersonInfo info){
      if (isAccepted(info))
      {
            cout << "Hired" << endl;
      } else {
            cout << "Rejected" << endl;
      }  
}

int main(){

      PrintResult(ReadInfo());
     
      return 0;
}