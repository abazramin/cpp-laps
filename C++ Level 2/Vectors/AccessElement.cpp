#include <iostream>
using namespace std;

int main(){

      vector<int> nums = {1,2,3,4,5};


      nums[1] = 53;



      // cout << nums[1] * 10 << endl;


      // cout << nums.at(4) + 10 << endl;
      

      nums.at(3) = 20;


      // cout << nums.at(3) << endl;



      vector<int>::iterator itr;

      for (itr = nums.begin(); nums.end() != itr; itr++)
      {
            cout << *itr << endl;
      }


      for (itr = nums.begin(); nums.end() != itr; itr++)
      {
            cout << &(*itr) << endl;
      }
      

      return 0;
}