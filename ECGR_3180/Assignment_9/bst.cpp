/*
* Implement the find() method for the BST which returns the value if the key is
present, empty string otherwise.
* Your implemntation can be either iterative or recursive.
*/
#include <iostream>
#include <string>

using namespace std;

class Node{
private:
    int key;
    string val;
    Node* left;
    Node* right;

friend class BinarySearchTree;
};

class BinarySearchTree{
public:
    BinarySearchTree(): root{nullptr} {}
    void insert(int key, string val); // Recursive
    void printInOrder() const; // Prints keys in-order. Recursive
    string find(int key) const; //Returns value if node is present, else return empty string. Iterative

private:
    Node* root;
    void insertHelper(Node* parent, Node* new_node);
    void printInOrderHelper(Node *n) const; //Helper for recursive implemenation of printInroder()
};

void BinarySearchTree::insert(int key, string val){
    Node* new_node = new Node;
    new_node->key = key;
    new_node->val = val;
    new_node->left = nullptr;
    new_node->right = nullptr;

    if (root == nullptr) root = new_node;
    else insertHelper(root, new_node);  
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node){
    if (new_node->key < parent->key) {
        if (parent->left == nullptr) parent->left = new_node;
        else insertHelper(parent->left, new_node); 
    }

    else if (new_node->key > parent->key) {
        if (parent->right == nullptr) parent->right = new_node;
        else insertHelper(parent->right, new_node);
    }
}

string BinarySearchTree::find(int key) const{
    // Your code here
    Node* current = root;
    while(current != nullptr){
        if (key == current->key) return current->val;

        else if (key > current->key) current = current->right;
        
        else current = current->left;
    }

    return "";
}

void BinarySearchTree::printInOrder() const {
    if (root == nullptr) cout << endl;
    
    printInOrderHelper(root);
    cout << endl;
}

void BinarySearchTree::printInOrderHelper(Node* n) const{
    if (n == nullptr) return;
    
    printInOrderHelper(n->left);
    cout << n->key << " ";
    printInOrderHelper(n->right);
}

int main(){
    BinarySearchTree t;

    t.insert(5, "Boron");
    t.insert(3, "Lithium");
    t.insert(7, "Nitrogen");
    t.insert(2, "Helium");
    t.insert(4, "Berylium");
    t.insert(6, "Carbon");
    t.insert(8, "Oxygen");

    t.printInOrder(); // Prints the keys in order (will appear sorted)

    int ele = 8;
    string val = t.find(ele);

    if (val == "" ) cout << ele << " does not exist in tree" << endl;
    else cout << ele << " : " << val << endl;
    
    ele = 0;
    val = t.find(ele);

    if (val == "" ) cout << ele << " does not exist in tree" << endl;
    else cout << ele << " : " << val << endl;
    return 0;
}