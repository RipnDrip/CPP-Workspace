#include <string>
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    NodeType<T> *temp;
    while (head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
void DoublyLinkedList<T>::insertItem(T &item) {
    NodeType<T> *node = new NodeType<T>;
    node->data = item;
    node->next = nullptr;
    node->back = nullptr;

    if (head == nullptr){
        head = node;
        tail = head;
        return;
    }
    if (node->data < head->data){
        node->next = head;
        head = node;
        return;
    }
    if (node->data >= tail->data){
        node->back = tail;
        tail->next = node;
        tail = node;
        return;
    }

    NodeType<T> *curr = head;
    while (curr && (node->data >= curr->data)){
        curr = curr->next;
    }
    if (curr){
        node->next = curr;
        node->back = curr->back;
        curr->back->next = node;
        curr->back = node;
        return;
    }
    return;
}

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
    NodeType<T>* current = head;
    bool deleted = false;
    if (head == nullptr){
        cout << "You cannot delete from an empty list." << endl;
        return;
    }
    else if (head->data == item){
        current = head->next;
        delete head;
        head = current;
        deleted = true;
    }
    else if (tail->data == item){
        current = tail->back;
        current->next = nullptr;
        tail->next = nullptr;
        tail->back = nullptr;
        delete tail;
        tail = current;
        deleted = true;
    }
    else {
        while (current->next != nullptr){
            if (current->next->data == item){
                current->next = current->next->next;
                if (current->next != nullptr){
                    delete current->next->back;
                    deleted = true;
                    current->next->back = current;
                }
                break;
            }
            current = current->next;
        }

    }

    if (!deleted){
        cout << "Item not in list!" << endl;
    }
}

template<class T>
int DoublyLinkedList<T>::lengthIs() const {
    int length;
    if (head != nullptr){
        NodeType<T> *current = head;
        while (current != nullptr){
            length++;
            current = current->next;
        }
    }
    return length;
}

template<class T>
void DoublyLinkedList<T>::print() {
    NodeType<T> *elem = head;
    while (elem != nullptr){
        cout << elem->data << " ";
        elem = elem->next;
    }
    cout << endl;
}

template<class T>
void DoublyLinkedList<T>::printReverse() {
    NodeType<T> *elem = tail;
    while (elem != nullptr){
        cout << elem->data << " ";
        elem = elem->back;
    }
    cout << endl;
}

template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &lower, T &upper) {
    if (head != nullptr){
        NodeType<T> *current = head;

        while (current != nullptr){
            NodeType<T> *next = current->next;
            if (current->data >= lower && current->data <= upper){
                deleteItem(current->data);
                current = next;
            }
            else current = current->next;
        }
    }
}

template<class T>
T DoublyLinkedList<T>::mode() {
    T mod = 0;
    int m=0;
    int c=0;

    if(head==NULL){
        return mod;
    }
    NodeType<T> *t = head->next;
    mod = head->data;
    T prev = head->data;
    m = 1;
    c = 1;
    while(t!=NULL){
        if(t->data == t->back->data){
            c++;
        }
        else{
            if(c>m){
                m = c;
                c = 1;
                mod = prev;
            }
        }
        prev = t->data;
        t = t->next;
    }
    return mod;
}

template<class T>
void DoublyLinkedList<T>::swapAlternate(){
    if(head==NULL || head==tail){
        return;
    }
    NodeType<T> *curr = head, *prev = NULL;
    while (curr != NULL && curr->next != NULL) {
        NodeType<T> *temp = curr->next;
        curr->next = temp->next;
        if(temp->next!=NULL){
            temp->next->back = curr;
        }
        temp->next = curr;
        curr->back = temp;

        if (&prev->data == NULL) {
            head = temp;
            temp->back = NULL;
        }
        else {
            prev->next = temp;
            temp->back = prev;
        }

        prev = curr;
        curr = curr->next;
    }
    if(curr==NULL){
        tail = prev;
    }
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;


