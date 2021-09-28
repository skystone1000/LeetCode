// Binary Search Tree
// 06 #0450 Delete Node in a BST

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
    
    int inorder_predecessor(TreeNode* root){
        root = root -> left;
        while(root->right)
            root = root->right;
        return root->val;
    }
    
    int inorder_successor(TreeNode* root){
        root = root->right;
        while(root->left)
            root = root->left;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        // Searching the element
        if(key > root->val){
            root -> right = deleteNode(root->right, key);
        }
        else if(key < root->val){
            root -> left = deleteNode(root->left, key);
        }
        
        // Once element is found
        else{
            if(!root->left && !root->right) 
                root = NULL;
            // Find Inorder predecessor
            else if(root->left){
                root->val = inorder_predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
            // Find Inorder successor
            else{
                root->val = inorder_successor(root);
                root->right = deleteNode(root->right, root->val);
            }
        }
        
        return root;
    }
};
