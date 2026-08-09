#include <iostream>
using namespace std;



bool isHasDriveLicenensWithRecommending(){
      bool HasRecommending;
      short Age;
      bool HasDriveLicences;

        cout << "Do You Have a Recommending ? Enter 1 if You Have it , And 0 if you did't" << endl;
      cin >> HasRecommending;


      if (HasRecommending) {
            cout << "Hire" << endl;
            return true;
      } else {

      //
      cout << "Enter Your Age" << endl;
      cin >> Age;
      //
      cout << "Do You Have a Drive Licences ? Enter 1 if You Have it , And 0 if you did't" << endl;
      cin >> HasDriveLicences;
      //
      if (Age >= 21 && HasDriveLicences == true)
      {
           return true;
      } 
      }

      
      return false;
}

bool isHasDriveLicenensWithRecommending(bool HasRecommending){

      if (HasRecommending)
            return true;
      
     
      return false;
}

bool isHasDriveLicenensWithNoRecommending(int Age, bool HasDriveLicences){

     
      if (Age >= 21 && HasDriveLicences == true)
           return true;

      return false;
}
int main(){


      bool isHasRecommending;
      short Age;
      bool isHasDriveLicences;

      cout << "Do You Have Recommending ?" << endl;
      cin >> isHasRecommending;
      
      if(isHasRecommending){
            isHasDriveLicenensWithRecommending(isHasRecommending);
            cout << "Hire" << endl;
      } else
      {
            cout << "Enter The Age ?" << endl;
            cin>> Age;
            
            cout << "Enter if Have Drive Lieces" <<endl;
            cin >> isHasDriveLicences;
            //
            bool result = isHasDriveLicenensWithNoRecommending(Age,isHasDriveLicences);  
            //
            if (result)
            {
               cout << "Hire" << endl;     
            } else{
              cout << "Reject" << endl;
            }
            
            
      }



      return 0;
}