#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {

  if(fork() == 0) {
    // child
    cout << "in child" << endl;
  } else {
    // parent
    cout << "in parent" << endl;
  }
  
  return 0;
}
