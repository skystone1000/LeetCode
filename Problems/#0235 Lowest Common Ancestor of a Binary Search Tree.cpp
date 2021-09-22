// Company Amazon
// 11 #0235 Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Method 1 (Recursive)
        // Time - O(n)  Space - O(n)
        /*
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left , p , q);
        }else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;   
        } 
        */
        
        // method 2 (Iterative)
        // Time - O(n)  Space - O(1)
        while(root != NULL){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }else{
                return root;   
            } 
        }
        return NULL;
        
    }
};