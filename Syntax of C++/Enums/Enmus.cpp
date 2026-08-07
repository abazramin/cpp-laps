#include <iostream>
using namespace std;

enum OurColor {Red , Blue , Yallow , Black};
enum Gender {Male , Famale};
enum Week {son , mon , str , ther , fri};
enum stauts {active , notactive};

int main() {
   

      OurColor colors;

      colors = OurColor::Red;
      


      cout << colors << endl;

    return 0;
}