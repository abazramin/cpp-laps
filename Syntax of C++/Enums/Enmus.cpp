#include <iostream>
#include <string>
using namespace std;

enum OurColor {Red , Blue , Yallow , Black};
enum Gender {Male , Famale};
enum Week {son , mon , str , ther , fri};
enum stauts {active , notactive};

int main() {
   

      OurColor colors;

      colors = OurColor::Red;
      
      string num = "23456";

      int n = stoi(num);



      cout << colors << endl;

    return 0;
}