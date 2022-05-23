#include <cstdlib>
#include <iostream>
#include "Account.h"

using namespace std;

/*
 * This file contains the "Driver" code for this project.
 */

 /*
  * This is the main method of your program. You should write code here which tests all
  * aspects of your Account class implementation. You are responsible for thoroughly
  * testing your code.
  *
  * Please note: code in this file will not be used in grading evaluation of your
  * assignment. We will use our own driver file which will use YOUR provided Account
  * implementation to test against project requirements.
  */
int main() {


  Account me("Terique Mick");
  Account bro("John Doe");
  Account guy;

  me.setBalance(100);
  cout << me.getName() << "'s balance is: "<< me.getBalance() << endl;

  me.deposit(50);
  cout <<  me.getName() << "'s balance is: "<< me.getBalance() << endl;

  me.withdraw(25);
  cout <<  me.getName() << "'s balance is: "<< me.getBalance() << endl;
  
  me.interest(0.5);
  cout << me.getName() << "'s balance is: "<<  me.getBalance() << endl;

  bro.setBalance(100);
  bro.transferTo(50, guy);

  cout << bro.getName() << "'s balance is: "<<  bro.getBalance() << endl;
  cout << guy.getName() << "'s balance is: "<<  guy.getBalance() << endl;

  //return EXIT_SUCCESS;
}
