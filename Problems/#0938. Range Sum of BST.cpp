// Company Amazon
// 45 #0938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root == NULL) return sum;
        
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr = qu.front();
            qu.pop();
            if(curr->val >= low && curr->val <= high){
                sum += curr->val;
            }
            
            if(curr->left != NULL && curr->val > low){
                qu.push(curr->left);
            }
            if(curr->right != NULL && curr->val < high){
                qu.push(curr->right);
            }
        }
        
        
        return sum;
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        inOrd(root, sum, low, high);
        return sum;
    }
    
    void inOrd(TreeNode* root, int& sum, int low, int high){
        if(root == NULL) {
            return ;
        }
        
        inOrd(root->left, sum, low, high);
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        inOrd(root->right, sum, low, high);
    }
};