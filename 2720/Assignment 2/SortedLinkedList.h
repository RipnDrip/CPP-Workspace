#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ListNode.h"
#include "ItemType.h"


class SortedLinkedList {

private:
  int size;
  ListNode *head;
  ListNode *currentPos;

 public:
  SortedLinkedList();
  ~SortedLinkedList();
  void deleteEnd();
  int length() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType item);
  ItemType GetNextItem();
  void ResetList();
  void printList();
  void mergefunction(SortedLinkedList &newList);
  SortedLinkedList deleteAltNodes();
  void intersection(SortedLinkedList &newList);

};



#endif //SORTEDLINKEDLIST_H       