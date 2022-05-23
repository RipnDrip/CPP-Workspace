#ifndef ASSN04_BINARYTREE_H
#define ASSN04_BINARYTREE_H

template<class T>
struct NodeType {
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
};

template<class T>
class BinaryTree {
    public:
    bool duplicateItemFound;
    BinaryTree();
    ~BinaryTree();
    void insert(T &key);
    void putItem(NodeType<T>*&tree , T item);
    void deleteItem(T &key);
    void deleting(NodeType<T> *&tree, T &key);
    void deletion(NodeType<T>* &tree);
    void getPredecessor(NodeType<T>* tree, T& data);
    void retrieve(T &item, bool &found) const;
    void preOrder() const;
    void inOrder()  const; 
    void postOrder() const;
    int getLength() const;
    int getNumSingleParent() const; // returns amount of nodes with ONE child
    int singleParent(NodeType<T>* tree) const;
    int getNumLeafNodes() const; // returns amount of nodes with no children
    int leaves(NodeType<T>* tree) const;
    void getSumOfSubtrees(NodeType<T>* tree, T& item); 
    void sum(NodeType<T>* tree, T& item);
    bool checkDup(T& item, bool& found);
    void checkDupUtil(NodeType<T>* tree, T& item, bool& found);
private:
    NodeType<T> *root;
 
};
#endif