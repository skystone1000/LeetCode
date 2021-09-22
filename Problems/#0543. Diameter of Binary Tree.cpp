// Company Amazon
// AIE 12.2 #0543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) 
            return 0;
        
        int res = INT_MIN;
        calculateDia(root, res);
        return res-1;
    }
    
    int calculateDia(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        
        int l = calculateDia(root->left, res);
        int r = calculateDia(root->right, res);
        
        int temp = max(l,r) + 1;
        int ans = max(temp, l+r+1);
        res = max(res,ans);
        return temp;
    }
};
