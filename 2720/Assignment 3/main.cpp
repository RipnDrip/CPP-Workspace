#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"

using namespace std;

string input_file;

void switchLogic(DoublyLinkedList<int> &list);
void switchLogic(DoublyLinkedList<float> &list);
void switchLogic(DoublyLinkedList<string> &list);

bool quit = false;

int main(int argc, const char *argv[]) {
    input_file = argv[1];
    ifstream inClientFile;
    inClientFile.open(input_file);
    if (!inClientFile.is_open()){
        cerr << "File could not be opened" << endl;
        exit(0);
    }

    cout << "Enter list type (i - int, f - float, s - std::string):";
    char listType;
    cin >> listType;
    cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r),"
            " swapAtl (s), quit (q)" << endl;

    if (listType == 'i'){
        DoublyLinkedList<int> *list = new DoublyLinkedList<int>();
        int value;
        while (inClientFile >> value){
            list->insertItem(value);
        }
        list->print();
        while (quit == false) switchLogic(*list);
        cout << "Quitting program..." << endl;
        exit(0);
    }
    else if (listType == 'f'){
        DoublyLinkedList<float> *list = new DoublyLinkedList<float>();
        float value;
        while (inClientFile >> value){
            list->insertItem(value);
        }
        list->print();
        while (quit == false) switchLogic(*list);
        cout << "Quitting program..." << endl;
        exit(0);
    }
    else {
        DoublyLinkedList<string> *list = new DoublyLinkedList<string>();
        string value;
        while (inClientFile >> value){
            list->insertItem(value);
        }
        list->print();
        while (quit == false) switchLogic(*list);
        cout << "Quitting program..." << endl;
        exit(0);
    }


}

void switchLogic(DoublyLinkedList<int> &list) {
    cout << "Enter a command:";

    char command;
    cin >> command;
    int input;
    int mode;
    switch (command){
        case 'i':
            cout << "Item to insert:";
            cin >> input;
            list.insertItem(input);
            list.print();
            break;
        case 'd':
            cout << "Item to delete:";
            cin >> input;
            list.deleteItem(input);
            list.print();
            break;
        case 'l':
            cout << "The length is: ";
            cout << to_string(list.lengthIs()) << endl;
        case 'p':
            list.print();
            break;
        case 'b':
            cout << "Enter lower bound:";
            int lower;
            cin >> lower;
            cout << "Enter upper bound:";
            int upper;
            cin >> upper;
            cout << "Original List: ";
            list.print();
            list.deleteSubsection(lower, upper);
            cout << "Modified List: ";
            list.print();
            break;
        case 'm':
            list.print();
            mode = list.mode();
            cout << "Mode: " + to_string(mode) << endl;

            break;
        case 'r':
            list.printReverse();
            break;
        case 's':
            cout << "Original List: ";
            list.print();
            list.swapAlternate();
            cout << "Swapped List: ";
            list.print();
            break;
        case 'q':
            quit = true;
    }
}

void switchLogic(DoublyLinkedList<float> &list) {
    cout << "Enter a command:";

    char command;
    cin >> command;
    float input;
    float mode;
    switch (command){
        case 'i':
            cout << "Item to insert:";
            cin >> input;
            list.insertItem(input);
            list.print();
            break;
        case 'd':
            cout << "Item to delete:";
            cin >> input;
            list.deleteItem(input);
            list.print();
            break;
        case 'l':
            cout << "The length is: ";
            cout << to_string(list.lengthIs()) << endl;
        case 'p':
            list.print();
            break;
        case 'b':
            cout << "Enter lower bound:";
            float lower;
            cin >> lower;
            cout << "Enter upper bound:";
            float upper;
            cin >> upper;
            cout << "Original List: ";
            list.print();
            list.deleteSubsection(lower, upper);
            cout << "Modified List: ";
            list.print();
            break;
        case 'm':
            list.print();
            mode = list.mode();
            cout << "Mode: " + to_string(mode) << endl;
            break;
        case 'r':
            list.printReverse();
            break;
        case 's':
            cout << "Original List: ";
            list.print();
            list.swapAlternate();
            cout << "Swapped List: ";
            list.print();
            break;
        case 'q':
            quit = true;
    }
}

void switchLogic(DoublyLinkedList<string> &list) {
    cout << "Enter a command:";

    char command;
    cin >> command;
    string input;
    string upper;
    string lower;
    string mode;
    switch (command){
        case 'i':
            cout << "Item to insert:";
            cin >> input;
            list.insertItem(input);
            list.print();
            break;
        case 'd':
            cout << "Item to delete:";
            cin >> input;
            list.deleteItem(input);
            list.print();
            break;
        case 'l':
            cout << "The length is: ";
            cout << to_string(list.lengthIs()) << endl;
        case 'p':
            list.print();
            break;
        case 'b':
            cout << "Enter lower bound:";
            cin >> lower;
            cout << "Enter upper bound:";
            cin >> upper;
            cout << "Original List: ";
            list.print();
            list.deleteSubsection(lower, upper);
            cout << "Modified List: ";
            list.print();
            break;
        case 'm':
            list.print();
            mode = list.mode();
            cout << "Mode: " + mode << endl;
            break;
        case 'r':
            list.printReverse();
            break;
        case 's':
            cout << "Original List: ";
            list.print();
            list.swapAlternate();
            cout << "Swapped List: ";
            list.print();
            break;
        case 'q':
            quit = true;
    }
}
