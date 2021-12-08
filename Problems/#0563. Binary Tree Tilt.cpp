// #0563. Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumTilt = 0;
    
    int findTilt(TreeNode* root) {
        calSum(root);
        return sumTilt;
    }
    
    int calSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftSum = calSum(root->left);
        int rightSum = calSum(root->right);
        
        sumTilt += abs(leftSum - rightSum);
        
        return leftSum + rightSum + root->val;
    }
};
