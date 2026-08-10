#include <iostream>
#include <cmath>
using namespace std;

void TaskDurationInSeconds(float totalSecound){
      

      float reminder;
      float  SecoundPerDay = (24 * 60 * 60);
      float  SecoundPerHours = (60 * 60);
      float  SecoundPerMinetus = (60);

      float totalDay = floor(totalSecound / SecoundPerDay);
      reminder = (totalSecound / SecoundPerDay);

      float totalHours = floor(totalSecound / SecoundPerHours);
      reminder = reminder / SecoundPerHours;

      float totalMintus = floor(totalSecound / SecoundPerMinetus);
      reminder = reminder / SecoundPerMinetus;

      float totalSecounds = reminder;



      cout << "The Result is : " << totalDay << " : " << totalHours << " : " << totalMintus << " : " << totalSecounds << endl;


}


int main() {
      // here we will convert the total secound into days, hours, minutes
      float totalSecound;
      cout << "Enter Total Of Secound" << endl;
      cin >> totalSecound;



      TaskDurationInSeconds(totalSecound);



      return 0;
}