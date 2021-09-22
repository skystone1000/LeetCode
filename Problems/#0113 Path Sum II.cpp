// Company Amazon
// 26 #0113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> curr;
        findPaths(root, sum, curr , paths);
        return paths;
    }
    
    void findPaths(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& paths){
        if(root == NULL) return ;
        
        curr.push_back(root->val);
        if(root->val == sum && root->left == NULL && root->right == NULL){
            paths.push_back(curr);
            return ;
        }
        vector<int> temp(curr);
        vector<int> temp2(curr);
        findPaths(root->right, sum - root->val, temp, paths);
        findPaths(root->left, sum - root->val, temp2, paths);
    }
};