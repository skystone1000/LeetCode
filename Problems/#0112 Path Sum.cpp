// Company Amazon
// 07 #0112 Path Sum
// https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        
        if(root->right == NULL && root->left == NULL)
            if(root->val - sum == 0)
                return true;
    
        /*  Same as below line
        if(hasPathSum(root->right, sum - root->val) == true)
            return true;
        if(hasPathSum(root->left, sum - root->val) == true)
            return true;
        return false;
        */
        
        return hasPathSum( root->left, sum-root->val) || hasPathSum( root->right, sum-root->val) ;
    }
};