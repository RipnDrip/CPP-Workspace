#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
#include <unistd.h>


enum Comparison {
                 GREATER,EQUAL,LESS
};

class ItemType {

private:
  int value;

 public:
  //default constructor                                                                                                                                                             
  ItemType();

  Comparison compareTo(ItemType item); // Compare the value of item with the currentobject's value and return GREATER, LESS or EQUAL.                                               

  int getValue() const; // Return the value instance variable                                                                                                                       

  void initialize(int num); // Initializes the data member by variable num                                                                                                          

};

#endif //ITEMTYPE_H                                                                                                                                                                 

