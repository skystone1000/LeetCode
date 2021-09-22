// Company Amazon
// #0226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* root){
        if(root == NULL)
            return;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        invertTree(left);
        invertTree(right);
        
        root->left = right;
        root->right = left;
    }
};


// root->left && root->right != NULL checks are only required when we 
// do not add the base check root == NULL 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* root){
        if(root == NULL)
            return;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if(root->left != NULL){
            invertTree(left);
        }
        if(root->right != NULL){
            invertTree(right);
        }
        
        root->left = right;
        root->right = left;
    }
};