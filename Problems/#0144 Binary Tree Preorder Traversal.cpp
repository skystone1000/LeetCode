// Binary Tree 01
// 01 #0144 Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }
    
    void preOrder(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};