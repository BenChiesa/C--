/*
* Leetcode #107
* Write a method that returns the height of a binary tree
* Note: DO NOT modify the binary tree.
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int ele;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : ele{0}, left{nullptr}, right{nullptr}, parent{nullptr} {}
    TreeNode(int x) : ele{x}, left{nullptr}, right{nullptr}, parent{nullptr} {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : ele{x}, left{left},
    right{right}, parent{nullptr} {}
};

int treeHeight(TreeNode *p) {
    // Your code here
    if(p == nullptr) return 0;
    
    int left = treeHeight(p->left);
    int right = treeHeight(p->right);
 
    return 1 + max(left, right);   
}

// Test
int main() {
    // Test 1
    TreeNode t1(15); // leaf
    TreeNode t2(7); // leaf
    TreeNode t3(9); // leaf
    TreeNode t5(20, &t1, &t2); // internal node
    TreeNode t6(3, &t3, nullptr); // internal node
    TreeNode t7(1, &t5, &t6); // root
    cout << treeHeight(&t7) << endl; // 3
    // Test 2
    TreeNode n4(4, nullptr, nullptr); // leaf
    TreeNode n3(3, nullptr, &n4); // internal node
    TreeNode n2(2, &n3, nullptr); // internal node
    TreeNode n1(1, nullptr, &n2); // root
    cout << treeHeight(&n1) << endl; // 4
}
