// Binary Search Tree
// 10 #0110 Balanced Binary Tree

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
    bool isBalanced(TreeNode* root) {
        return (getHeight(root) >= 0);
    }
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        
        if(left_height < 0 || right_height < 0 
           || abs(left_height - right_height) > 1){
            return -1;
        }
        
        return max(left_height, right_height) + 1;
    }
};