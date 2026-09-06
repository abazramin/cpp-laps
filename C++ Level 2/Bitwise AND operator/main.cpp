#include <iostream>
using namespace std;



int  main()
{
      int a = 5;
      int b = 3;

      cout << "a & b = " << (a & b) << endl; // Bitwise AND
      cout << "a | b = " << (a | b) << endl; // Bitwise OR
      cout << "a ^ b = " << (a ^ b) << endl; // Bitwise XOR
      cout << "~a = " << (~a) << endl;       // Bitwise NOT
      cout << "a << 1 = " << (a << 1) << endl; // Left shift
      cout << "b >> 1 = " << (b >> 1) << endl; // Right shift

      return 0;
}