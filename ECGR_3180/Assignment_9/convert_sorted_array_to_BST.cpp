#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.empty()) return NULL;
    
    int mid = nums.size() / 2; // Find the middle element
    TreeNode* root = new TreeNode(nums[mid]);
    
    vector<int> leftSubarray(nums.begin(), nums.begin() + mid);
    vector<int> rightSubarray(nums.begin() + mid + 1, nums.end());
    
    root->left = sortedArrayToBST(leftSubarray);
    root->right = sortedArrayToBST(rightSubarray);
    
    return root;
}

void inorderTraversal(TreeNode* root){
    if(root){
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = sortedArrayToBST(nums);
    cout << "Inorder traversal of the resulting tree: " << endl;
    inorderTraversal(root);

    nums = {-10, -3, 0, 5, 9};
    root = sortedArrayToBST(nums);
    cout << endl << "Inorder traversal of the resulting tree: " << endl;
    inorderTraversal(root);

    nums = {1, 3};
    root = sortedArrayToBST(nums);
    cout << endl << "Inorder traversal of the resulting tree: " << endl;
    inorderTraversal(root);
    return 0;
}
