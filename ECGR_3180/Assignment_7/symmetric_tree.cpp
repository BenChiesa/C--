#include <iostream>

using namespace std;

    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
            
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;   
        
        if(left == nullptr || right == nullptr) return false;
        
        return (left->val == right->val) && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return 0;
        
        return isSymmetricHelper(root->left, root->right);
    }

int main() {
    // Test 1: A symmetric tree
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(2);
    TreeNode t4(3);
    TreeNode t5(4);
    TreeNode t6(4);
    TreeNode t7(3);
    
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    if (isSymmetric(&t1)) cout << "Test 1: Symmetric tree" << endl;
    
    else cout << "Test 1: Not symmetric" << endl;
    

    // Test 2: An asymmetric tree
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    TreeNode n4(3);
    TreeNode n5(3);
    
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.right = &n5;

    if (!isSymmetric(&n1)) cout << "Test 2: Not symmetric" << endl;
    
    else cout << "Test 2: Symmetric tree" << endl;
    
    
    return 0;
}