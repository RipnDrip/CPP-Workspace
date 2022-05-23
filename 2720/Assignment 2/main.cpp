#include <unistd.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;



int main(int argc, char *argv[]) {

  SortedLinkedList list;
  ListNode head;

  string fileName = argv[1];
  ifstream file(argv[1]);
  file.open(fileName.c_str());
  if (!file.is_open()) {
    cout << "Text File not found!" << endl;
    exit(EXIT_FAILURE);
  }
  string value;

  while(file >> value) {
    ItemType item;
    item.initialize(stoi(value));
    list.insertItem(item);
  } //reads file into list                                                                                                                                                          



  cout << "Commands: " << endl;
  cout << "(i) - Insert Value" << endl;
  cout << "(d) - Delete Value" << endl;
  cout << "(s) - Search Value" << endl;
  cout << "(n) - Print next iterator value" << endl;
  cout << "(r) - Reset iterator" << endl;
  cout << "(a) - Delete Alternate Nodes" << endl;
  cout << "(m) - Merge two lists" << endl;
  cout << "(t) - Intersection" << endl;
  cout << "(p) - Print list" << endl;
  cout << "(l) - Print length" << endl;
  cout << "(q) - Quit program" << endl;

   bool inputIsValid = true;
  while (inputIsValid) {
    cout << "Enter a command: ";
    char userCommand;
    cin >> userCommand;

    if (userCommand == 'i') {
      string input;
      list.printList();
      cout << "Enter number: ";
      cin >> input;
      ItemType item;
      item.initialize(stoi(input));
      list.insertItem(item);
      list.printList();
    }

    else if (userCommand == 'd') {
      int num;
      list.printList();
      cout << "Enter value to delete: ";
      cin >> num;
      ItemType item;
      item.initialize(num);
      list.deleteItem(item);
      list.printList();
    }

    else if (userCommand == 's') {
      int num;
      cout << "Enter a value to search: ";
      cin >> num;
      ItemType item;
      item.initialize(num);
      if(list.searchItem(item) != -2) {
        cout << "Index" << list.searchItem(item) << endl;
        cout << "Item not found." << endl;
      }
    }
  else if (userCommand == 'n') {
      if (list.length() == 0) {
        cout << "List is empty" << endl;
      }
      else {
        for(int i = 0; i < list.length(); i++) {
          list.GetNextItem();
        }
      }
      cout << "The end of the list has reached." << endl;
    }

    else if (userCommand == 'r') {
      list.ResetList();
    }

    else if (userCommand == 'a') {
      cout << "List before alternate delete: ";
      list.printList();
      cout << "List after alternate delete: ";
      list.deleteAltNodes();
      list.printList();
    }
     else if (userCommand == 'm') {
      int listSize = 0;
      SortedLinkedList newList;
      ItemType item;
      cout << "Length of list to merge: ";
      cin >> listSize;

      string elements;
      cout << "List elements seperated by spaces in order: ";
      cin >> elements;
      cout << "List1: ";
      list.printList();
      cout << "List2: ";
      cout << elements << endl;
      item.initialize(stoi(elements));
      newList.insertItem(item);
      list.mergefunction(newList);
      list.printList();

    }
    else if (userCommand == 't') {
      int listSize = 0;
      SortedLinkedList newList;
      ItemType item;
      cout << "Length of list to merge: ";
      cin >> listSize;

      string elements;
      cout << "List elements seperated by spaces in order: ";
      cin >> elements;
      item.initialize(stoi(elements));
      newList.insertItem(item);

      cout << "List1: ";
      list.printList();
      cout << "List2: ";
      newList.printList();
      list.intersection(newList);
    }

    else if (userCommand == 'p') {
      list.printList();
    }

    else if (userCommand == 'l') {
      cout << "List length is " <<  list.length() << endl;
    }

    else if (userCommand == 'q') {
      cout << "Quitting program..." << endl;

      return 0;
    } else {
      inputIsValid = false;
      cout << "Invalid command, try again!" << endl;
    }
  } //while                                                                                                                                                                         
} //main  

