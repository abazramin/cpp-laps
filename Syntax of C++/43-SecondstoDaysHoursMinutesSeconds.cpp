#include <iostream>
#include <cmath>
using namespace std;




int main() {
      // here we will convert the total secound into days, hours, minutes
      float totalSecound;
      float reminder;
      cout << "Enter Total Of Secound" << endl;
      cin >> totalSecound;

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
      
      cout << totalDay << " : " << totalHours << " : " << totalMintus << " : " << totalSecounds << endl;  

      return 0;
}