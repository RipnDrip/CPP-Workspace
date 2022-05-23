#ifndef LISTNODE_H
#define LISTNODE_H
#include<stdio.h>
#include<stdlib.h>
#include "ItemType.h"

class ListNode {
public:
  ItemType item;
  ListNode *next;
};

#endif //LISTNODE_H  