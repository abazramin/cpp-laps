#include <iostream>
#include <cmath>
using namespace std;

float TaskDurationInSeconds(float numberOfDay , float numberOfHour , float numberOfMintus , float numberOfSecound){
      float totalOfSecounds = (numberOfDay * 24* 60 * 60) + (numberOfHour * 60 * 60 ) + (numberOfMintus * 60) + (numberOfSecound);
      return totalOfSecounds;
}


int main (){


      float numberOfDay;
      float numberOfHour;
      float numberOfMintus;
      float numberOfSecound;

      cout << "Write Your number of day task " << endl;
      cin >> numberOfDay;

      cout << "Write Your number of hour task " << endl;
      cin >> numberOfHour;

      cout << "Write Your number of minetus task " << endl;
      cin >> numberOfMintus;

      cout << "Write Your number of Secound task " << endl;
      cin >> numberOfSecound;

      float totalOfSecounds = TaskDurationInSeconds(numberOfDay , numberOfHour , numberOfMintus , numberOfSecound);


      cout << " The Result is : " << totalOfSecounds << " Secound" << endl;


      return 0;
}