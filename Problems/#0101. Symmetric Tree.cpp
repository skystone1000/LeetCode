// Company Amazon
// 29 #0101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSymmetric(root->right, root->left);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(right == NULL && left == NULL){
            return true;
        }else if(right == NULL || left == NULL){
            return false;
        }else if(right->val != left->val){
            return false;
        }else{
            return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
        }
    }
};