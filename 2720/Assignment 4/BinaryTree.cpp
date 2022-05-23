#include <string>
#include <iostream>
#include "BinaryTree.h"

using namespace std;
bool duplicateItemFound = false;
bool itemFound = false;

template <class T>
int CountNodes(NodeType<T> *tree);

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    if (root)
    {
        Destroy(root - left);
        Destroy(root - right);
        delete root;
    }
}

template <class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{
    obtain(root, item, found);
    if (found == true)
    {
        cout << "Item found in tree" << endl;
        itemFound = true;
    }
    else
    {
        cout << "Item not found in tree" << endl;
        itemFound = false;
    }
}

template <class T>
void obtain(NodeType<T> *tree, T &item, bool &found)
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (item < tree->key)
    {
        obtain(tree->left, item, found);
    }
    else if (item > tree->key)
    {
        obtain(tree->right, item, found);
    }
    else
    {
        item = tree->key;
        found = true;
        duplicateItemFound = found;
    }
}

template <class T>
void BinaryTree<T>::insert(T &item)
{
    if (checkDup(item, duplicateItemFound) != true)
    {
        putItem(root, item);
    }
    else
    {
        duplicateItemFound = false;
    }
}

template <class T>
void BinaryTree<T>::putItem(NodeType<T> *&tree, T item)
{

    if (tree == nullptr)
    {
        tree = new NodeType<T>();
        tree->left = nullptr;
        tree->right = nullptr;
        tree->key = item;
    }
    else if (item < root->key)
    {
        putItem(tree->left, item);
    }
    else if (item > root->key)
    {
        putItem(tree->right, item);
    }
    else {
        ::cout << "Item already in tree." << endl;
    }
}

template <class T>
void BinaryTree<T>::deleteItem(T &key)
{
    deleting(root, key);
}

template <class T>
void BinaryTree<T>::deleting(NodeType<T> *&tree, T &key)
{
    if (tree == NULL)
    {
        std::cout << "Item not in tree." << std::endl;
    }
    else if (key < tree->key)
    {
        deleting(tree->left, key);
    }
    else if (key > tree->key)
    {
        deleting(tree->right, key);
    }
    else
    {
        deletion(tree);
    }
}

template <class T>
void BinaryTree<T>::deletion(NodeType<T> *&tree)
{
    T data;
    NodeType<T> *temp;
    temp = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete temp;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete temp;
    }
    else
    {
        getPredecessor(tree->left, data);
        tree->key = data;
        deleting(tree->left, data);
    }
} // DeleteNode

template <class T>
void BinaryTree<T>::getPredecessor(NodeType<T> *tree, T &data)
{
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->key;
}

template <class T>
void BinaryTree<T>::inOrder() const
{
    printInOrder(root);
}

template <class T>
void BinaryTree<T>::preOrder() const
{
    printPreOrder(root);
}

template <class T>
void BinaryTree<T>::postOrder() const
{
    printPostOrder(root);
}

template <class T>
void printInOrder(NodeType<T> *tree)
{
    if (tree != NULL)
    {
        printInOrder(tree->left);
        cout << (tree->key) << " ";
        printInOrder(tree->right);
    }
}

template <class T>
void printPreOrder(NodeType<T> *tree)
{
    if (tree != NULL)
    {
        cout << (tree->key) << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

template <class T>
void printPostOrder(NodeType<T> *tree)
{
    if (tree != NULL)
    {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        cout << (tree->key) << " ";
    }
}

template <class T>
int BinaryTree<T>::getLength() const
{
    return CountNodes(root);
}

template <class T>
int CountNodes(NodeType<T> *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
    }
}

template <class T>
int BinaryTree<T>::getNumSingleParent() const
{
    return singleParent(root);
}

template <class T>
int BinaryTree<T>::singleParent(NodeType<T> *tree) const
{

    if (tree == NULL)
    {
        return 0;
    }
    else if (tree->right == NULL && tree->left != NULL)
    {
        return singleParent(tree->left) + 1;
    }
    else if (tree->right != NULL && tree->left == NULL)
    {
        return singleParent(tree->right) + 1;
    }
    else
    {
        return singleParent(tree->left) + singleParent(tree->right);
    }
}

template <class T>
int BinaryTree<T>::getNumLeafNodes() const
{
    return leaves(root);
}

template <class T>
int BinaryTree<T>::leaves(NodeType<T> *tree) const
{
    if (tree == NULL)
    {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return leaves(tree->left) + leaves(tree->right);
    }
}

template <class T>
void BinaryTree<T>::getSumOfSubtrees(NodeType<T> *tree, T &item) 
{
    return sum(tree, item);
}

template <class T>
void BinaryTree<T>::sum(NodeType<T> *tree, T &item)
{
    if (tree == NULL)
    {
        cout << "Item not in tree." << endl;
    }
    else if (item < tree->key)
    {
        sum(tree->left, item);
    }
    else if (item > tree->key)
    {
        sum(tree->right, item);
    }
    else
    {
        if (tree->right == NULL && tree->left != NULL)
        {
            cout << "Sum of Subtrees: " << tree->left->key << endl;
        }
        else if (tree->right != NULL && tree->left == NULL)
        {
            cout << "Sum of Subtrees: " << tree->right->key << endl;
        }
        else if (tree->right == NULL && tree->left == NULL)
            cout << "This node has no subtrees. " << endl;
        else
        {
            cout << "Sum of Subtrees: " << tree->left->key + tree->right->key << endl;
        }
    }
}

template <class T>
bool BinaryTree<T>::checkDup(T &item, bool &found)
{
    checkDupUtil(root, item, found);
    if (found == true)
    {
        cout << " Item already in tree" << endl;
    }
    return found;
}

template <class T>
void BinaryTree<T>::checkDupUtil(NodeType<T> *tree, T &item, bool &found)
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (item < tree->key)
    {
        obtain(tree->left, item, found);
    }
    else if (item > tree->key)
    {
        obtain(tree->right, item, found);
    }
    else
    {
        item = tree->key;
        found = true;
        duplicateItemFound = found;
    }
};
