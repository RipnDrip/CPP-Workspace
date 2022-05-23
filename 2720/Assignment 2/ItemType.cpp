#include <iostream>
#include <fstream>
#include "ItemType.h"
#include "ListNode.h"

ItemType:: ItemType() {
  value = 0;
}

int ItemType::getValue() const {
  return value;
}

Comparison ItemType:: compareTo(ItemType item){
  if(this->value>item.getValue())
    return GREATER;
  else if(this->value<item.getValue()){
    return LESS;
  }else{
    return EQUAL;
  }
}

void ItemType:: initialize(int num){
  value = num;
}