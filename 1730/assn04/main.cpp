#include <iostream>
#include "bitsum.h"
#include "bitsum.cpp"

using namespace std;

int numberOfOnes(unsigned long int);

int main()
{

  unsigned int a = 127;
  unsigned int b = 300221;
  unsigned int c = 55883222;
  unsigned int d = 6572382;
  unsigned int input;
  while (input != -1) {
    cout << "Enter an unsigned value: " << endl;
    cin >> input;
    cout << input << " has " << numberOfOnes(input) << " one(s)." << endl;
  }
  
  cout << endl;
  cout << "Here are test values:" << endl;
  cout << "a is: " << numberOfOnes(a) << endl;
  cout << "b is: " << numberOfOnes(b) << endl;
  cout << "c is: " << numberOfOnes(c) << endl;
  cout << "d is: " << numberOfOnes(d) << endl;
 return 0;
}