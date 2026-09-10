#include <iostream>
using namespace std;



int main(){

      int num;
      cout << "Plz Enter Want You Want Student to Add ?\n" ;
      cin >> num;

      float *ptr = new float[num];


      cout << "Enter grades of students." << endl;
      for (int i = 0; i < num; i++)
      {
            cout << "You Enterd Student : " << i + 1 << endl;
            cin >> *(ptr + i);
      }
      


      cout << "List of grades of students." << endl;
      for (int i = 0; i < num; i++)
      {
            cout << "You Enterd Student : " << *(ptr + i) << endl;
      }
      
      
      delete ptr;

      return 0;
}