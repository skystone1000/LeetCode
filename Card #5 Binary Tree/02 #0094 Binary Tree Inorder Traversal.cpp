// Binary Tree
// 02 #0094 Binary Tree Inorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inOrd(root);
        return ans;
    }
    
    void inOrd(TreeNode *root){
        if(root == NULL){
            return;
        }
        
        inOrd(root->left);
        ans.push_back(root->val);
        inOrd(root->right);
    }
};