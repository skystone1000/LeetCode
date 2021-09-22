// Company Amazon
// 28 #0104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

// Bottom Up Approach (Post Order Traversal)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){ return 0; }
        int left_depth = maxDepth(root -> left);
        int right_depth = maxDepth(root -> right);
        return max(left_depth, right_depth) + 1;
    }
};

// Top Down Approach (Pre Order Traversal)
class Solution2 {
public:
    int answer=0;
    int maxDepth(TreeNode* root) {
        calDepth(root,1);
        return answer;
    }
    
    void calDepth(TreeNode* root, int depth){
        if(root == nullptr){ return ; }
        
        if(root->left == nullptr && root->right == nullptr){
            answer = max(answer,depth);
        }
        
        calDepth(root->left,depth+1);
        calDepth(root->right,depth+1);
    }
};