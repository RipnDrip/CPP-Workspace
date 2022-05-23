#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;

string input_file;

void switchLogic(BinaryTree<int> &list);
void switchLogic(BinaryTree<float> &list);
void switchLogic(BinaryTree<string> &list);

bool quit = false;

int main(int argc, const char *argv[]) {
    //input_file = argv[0];
    //ifstream inClientFile;
    //inClientFile.open(input_file);
    cout << argv[1] << endl;
    fstream inClientFile;
    inClientFile.open(argv[1],ios::in);
    if (!inClientFile.is_open()){
        cerr << "File could not be opened" << endl;
        exit(0);
    }

    if (inClientFile.is_open()) {
    cout << "Enter tree type (i - int, f - float, s - std::string):";
    char listType;
    cin >> listType;
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o),"
            " getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees(t), quit (q)" << endl;

    if (listType == 'i'){
        
        BinaryTree<int> *list = new BinaryTree<int>();
        int value;
        while (inClientFile >> value){
            list->insert(value);
        }
        while (quit == false) switchLogic(*list);
        cout << "Quitting program..." << endl;
        exit(0);
    }
    else if (listType == 'f'){
        BinaryTree<float> *list = new BinaryTree<float>();
        float value;
        while (inClientFile >> value){
            list->insert(value);
        }
        
        while (quit == false) switchLogic(*list);
        cout << "Quitting program..." << endl;
        exit(0);
    }
    else {
        BinaryTree<string> *list = new BinaryTree<string>();
        string value;
        while (inClientFile >> value){
            list->insert(value);
        }

        while (quit == false) switchLogic(*list);
        cout << "Quitting program..." << endl;
        exit(0);
    }
    }
}

void switchLogic(BinaryTree<int> &list) {
    int input;
    bool found;
    char command;
    cout << "Enter a command:" << endl;
    cin >> command;
   
   while (command != 'i' && command != 'd'&& command != 'r'&& command != 'l'&& command != 'n'&& command != 'p' && command != 'o'&& command != 's'&& command != 'f'&& command != 't' && command != 'q') {
    cout << "Command not recognized. Try again." << endl;
    cout << "Enter a command:" << endl;
    cin >> command;
   }
    
    switch (command) {
        case 'i':{
            cout << "Item to insert:" << endl;;
            cin >> input;
            list.insert(input);
            list.inOrder();
            cout << endl;
            break;
        }    
        case 'd': {
            cout << "Item to delete:";
            cin >> input;
            list.deleteItem(input);
            list.inOrder();
            cout << endl;
            break;
        }    
        case 'r': {
            found = false;
            cout << "Item to be retrieved: ";
            cin >> input;
            cout << endl;
            list.retrieve(input, found);
            break;
        }        
        case 'l':{
            cout << "The length is: ";
            cout << to_string(list.getLength()) << endl;
        }
            
        case 'p': {
            cout << "Pre-Order: ";
            list.preOrder();
            cout << endl;
            break;
        }
            
        case 'n':{
            cout << "In-Order: ";
            list.inOrder();
            cout << endl;
            break;
        }
            
        case 'o':{
            cout << "Post-Order: ";
            list.postOrder();
            cout << endl;
            break;
        }
            
        case 's':{
            cout << "Number of Single Parents: ";
            int single = list.getNumSingleParent();
            cout << single << endl;
            break;
        }
        case 'f': {
            cout << "Number of leaf nodes: ";
            int leaf =list.getNumLeafNodes();
            cout << leaf << endl;
            break;
            }
        case 't': {
            NodeType<int>* node = new NodeType<int>();
            int value;
            cout << "Item to get sum of subtrees: ";
            cin >> value;
            node->key = value;
            list.getSumOfSubtrees(node, value);
            break;
        } 
        case 'q':{
            quit = true;
        }    
    }
}

void switchLogic(BinaryTree<float> &list) {
    float input;
    bool found;
    char command;
    cout << "Enter a command:" << endl;
    cin >> command;
   
   while (command != 'i' && command != 'd'&& command != 'r'&& command != 'l'&& command != 'n'&& command != 'p' && command != 'o'&& command != 's'&& command != 'f'&& command != 't' && command != 'q') {
    cout << "Command not recognized. Try again." << endl;
    cout << "Enter a command:" << endl;
    cin >> command;
   }
    switch (command) {
        case 'i':{
            cout << "Item to insert:";
            cin >> input;
            list.insert(input);
            list.inOrder();
            break;
        }    
        case 'd': {
            cout << "Item to delete:";
            cin >> input;
            list.deleteItem(input);
            list.inOrder();
            break;
        }    
        case 'r': {
            found = false;
            cout << "Item to be retrieved: ";
            cin >> input;
            list.retrieve(input, found);
            break;
        }        
        case 'l':{
            cout << "The length is: ";
            cout << to_string(list.getLength()) << endl;
        }
            
        case 'p': {
            cout << "Pre-Order: ";
            list.preOrder();
            break;
        }
            
        case 'n':{
            cout << "In-Order: ";
            list.inOrder();
            break;
        }
            
        case 'o':{
            cout << "Post-Order: ";
            list.postOrder();
            break;
        }
            
        case 's':{
            cout << "Number of Singele Parents: ";
            int single = list.getNumSingleParent();
            cout << single << endl;
            break;
        }
        case 'f': {
            cout << "Number of leaf nodes: ";
            int leaf =list.getNumLeafNodes();
            cout << leaf << endl;
            break;
            }
        case 't': {
            NodeType<float>* node = new NodeType<float>();
            float value;
            cout << "Item to get sum of subtrees: ";
            cin >> value;
            node->key = value;
            list.getSumOfSubtrees(node, value);
            break;
        } 
        case 'q':{
            quit = true;
        }    
    }
}

void switchLogic(BinaryTree<string> &list) {
    string input;
    string value;
    bool found;
    char command;
    cout << "Enter a command:" << endl;
    cin >> command;
   
   while (command != 'i' && command != 'd'&& command != 'r'&& command != 'l'&& command != 'n'&& command != 'p' && command != 'o'&& command != 's'&& command != 'f'&& command != 't' && command != 'q') {
    cout << "Command not recognized. Try again." << endl;
    cout << "Enter a command:" << endl;
    cin >> command;
   }
    
    
    switch (command) {
        case 'i':{
            cout << "Item to insert:";
            cin >> input;
            list.insert(input);
            list.inOrder();
            break;
        }    
        case 'd': {
            cout << "Item to delete:";
            cin >> input;
            list.deleteItem(input);
            list.inOrder();
            break;
        }    
        case 'r': {
            found = false;
            cout << "Item to be retrieved: ";
            cin >> input;
            list.retrieve(input, found);
            break;
        }        
        case 'l':{
            cout << "The length is: ";
            cout << to_string(list.getLength()) << endl;
        }
            
        case 'p': {
            cout << "Pre-Order: ";
            list.preOrder();
            break;
        }
            
        case 'n':{
            cout << "In-Order: ";
            list.inOrder();
            break;
        }
            
        case 'o':{
            cout << "Post-Order: ";
            list.postOrder();
            break;
        }
            
        case 's':{
            cout << "Number of Singele Parents: ";
            int single = list.getNumSingleParent();
            cout << single << endl;
            break;
        }
        case 'f': {
            cout << "Number of leaf nodes: ";
            int leaf =list.getNumLeafNodes();
            cout << leaf << endl;
            break;
            }
        case 't': {
            NodeType<string>* node = new NodeType<string>();
            string value;
            cout << "Item to get sum of subtrees: ";
            cin >> value;
            node->key = value;
            list.getSumOfSubtrees(node, value);
            break;
        }
            
        case 'q':{
            quit = true;
        }    
    }
   
}
