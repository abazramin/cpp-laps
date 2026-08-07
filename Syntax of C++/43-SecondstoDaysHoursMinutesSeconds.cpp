#include <iostream>
#include <cmath>
using namespace std;

int main(){

      float totalSecound;
      cout << "Enter Total Of Secound" << endl;
      cin >> totalSecound;


      float  SecoundPerDay = (24 * 60 * 60);
      float  SecoundPerHours = (60 * 60);
      float  SecoundPerMinetus = (60);

      float totalDay = totalSecound / SecoundPerDay;

      // write code here


      return 0;
}