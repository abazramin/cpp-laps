#include <iostream>
#include <cmath>
using namespace std;

void TaskDurationInSeconds(int totalSecound){
      

      int reminder;
      int  SecoundPerDay = (24 * 60 * 60);
      int  SecoundPerHours = (60 * 60);
      int  SecoundPerMinetus = (60);

      int totalDay = floor(totalSecound / SecoundPerDay);
      reminder = (totalSecound % SecoundPerDay);

      int totalHours = floor(totalSecound / SecoundPerHours);
      reminder = (reminder % SecoundPerHours);

      int totalMintus = floor(totalSecound / SecoundPerMinetus);
      reminder = (reminder % SecoundPerMinetus);

      int totalSecounds = reminder;



      cout << "The Result is : " << totalDay << " : " << totalHours << " : " << totalMintus << " : " << totalSecounds << endl;


}


int main() {
      // here we will convert the total secound into days, hours, minutes
      int totalSecound;
      cout << "Enter Total Of Secound" << endl;
      cin >> totalSecound;



      TaskDurationInSeconds(totalSecound);



      return 0;
}