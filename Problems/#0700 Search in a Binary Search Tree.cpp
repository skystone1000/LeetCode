// Binary Search Tree
// 04 #0700 Search in a Binary Search Tree

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        
        while(root != NULL){
            if(root->val == val){
                return root;
            }else if(val < root->val){
                root = root->left;
            } else{
                root = root->right;
            }
        }        
        return NULL;
    }
};