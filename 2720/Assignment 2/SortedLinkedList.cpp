#include <iostream>
#include <fstream>
#include "ListNode.h"
#include "ItemType.h"
#include "SortedLinkedList.h"


using namespace std;

  SortedLinkedList::SortedLinkedList() {
    size = 0;
    head=NULL;
    currentPos = NULL;
  }


  SortedLinkedList::~SortedLinkedList() {
    while (size != 0) {
      deleteEnd();
    }

  }


  void SortedLinkedList::deleteEnd() {
    if(head->next== nullptr){
      delete head;
      size=0;
      return;
    }
    if(head->next->next== nullptr){
      delete head->next;
      size--;
    }
    ListNode *temp = head;
    ListNode *tempNext = head->next;
    while(tempNext->next!= nullptr){
      temp = temp->next;
      tempNext = tempNext->next;
    }
    delete tempNext;
    size--;
  }


  int SortedLinkedList::length() const {
    return size;
  }
void SortedLinkedList::insertItem(ItemType item) {
    ListNode newNode;
    newNode->item = item;
    newNode->next = nullptr;

    if(head == NULL){
      head = newNode;
      return;
    }
    if(head->item.compareTo(item)==0){
      //duplicate                                                                                                                                                                   
      return;
    }

    ListNode *temp = head;
    ListNode *tempNext = head->next;

    while(tempNext!= nullptr && tempNext->item.compareTo(item)<0){
      if (tempNext->item.compareTo(item) == 0) {
        //duplicate                                                                                                                                                                 
        return;
      }
      temp=temp->next;
      tempNext = tempNext->next;
    }
    if(tempNext!= nullptr){//position found                                                                                                                                         
      newNode->next = tempNext;
      temp->next = newNode;
      size++;
    }
    else{
      temp->next = newNode;
      size++;
    }

  }
void SortedLinkedList::deleteItem(ItemType item) {
    if(head == nullptr){
      std::cout<<"Item not found"<<std::endl;
      return;
    }
    if(head->item.compareTo(item)==0){
      head = head->next;
      size--;
      return;
    }
    ListNode *temp = head;
    ListNode *tempNext = head->next;
    while(tempNext!= nullptr && tempNext->item.compareTo(item)!=0){
      temp = temp->next;
      tempNext = tempNext->next;
    }
    if(tempNext== nullptr){
      //item does not exist                                                                                                                                                         
      std::cout<<"Item not found"<<std::endl;
    }
    else{
      temp->next = tempNext->next;
      tempNext->next = nullptr;
      delete tempNext;
      size--;
    }
  }
  int SortedLinkedList::searchItem(ItemType item) {
    ListNode *temp = head;
    int index=0;
    while(temp!= nullptr){
      if(temp->item.compareTo(item)==0){
        return index;
      }
      index++;
      temp=temp->next;
    }
    cout << "Item not found";
    return index;
  }


  ItemType SortedLinkedList::GetNextItem() {
    if (head == nullptr) {
      currentPos = NULL;
      cout << "List is empty" << endl;
    } else if (currentPos->next == nullptr) {
      cout << "The end of the list has reached" << endl;
      currentPos = NULL;
    } else {
      ItemType item;
      currentPos = head;
      item = currentPos->item;
      return item;
    }
  }
  void SortedLinkedList::ResetList() {
    currentPos = NULL;
  }

  void SortedLinkedList::printList() {
    ListNode *temp = head;
    while(temp!= NULL){
      cout << temp->item.getValue() << endl;
      temp=temp->next;
    }
  }


  void SortedLinkedList::mergefunction(SortedLinkedList &newList) {

    ListNode *list2 = newList.head;

    while(list2 != nullptr) {
      ItemType item;
      int val = list2->item.getValue();
      item.initialize(val);
      insertItem(item);
      list2 = list2-> next;
    }
  }
  SortedLinkedList SortedLinkedList::deleteAltNodes() {
    SortedLinkedList newList;
    ItemType item;
    ListNode *temp;
    ListNode *loc;

    loc = currentPos;
    temp = head;

    if (length() % 2 != 0) {
      for(int i = 0; i < length() - 1; i+=2){
        loc = temp->next;
        item.initialize(loc->next->item.getValue());
        newList.insertItem(item);
        temp = temp->next;
      }
    } else {
      for(int i = 0; i < length() - 2; i+=2) {
        loc = temp->next;
        item.initialize(loc->next->item.getValue());
        newList.insertItem(item);
        temp = temp->next;
      }
    }
    return newList;
  }
  void SortedLinkedList::intersection(SortedLinkedList &newList) {
    ListNode *original = head;
    ListNode *other = newList.head;

    while(original != NULL) {
      if (original->item.getValue() == other->item.getValue()) {
        cout << original->item.getValue();
      }
        original = original->next;
    }
    original = head;
    other = original->next;

  }


