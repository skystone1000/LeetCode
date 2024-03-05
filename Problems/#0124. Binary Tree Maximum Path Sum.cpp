// #0124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
// Company Tag - AIE 12.2 Amazon, Meta, Google
// Difficulty - Hard

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromSubtree(root);
        return maxSum;
    }

private:
    int maxSum;
    int gainFromSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int gainFromLeft = max(gainFromSubtree(root->left), 0);
        int gainFromRight = max(gainFromSubtree(root->right), 0);
        maxSum = max(maxSum, gainFromLeft + gainFromRight + root->val);
        return max(gainFromLeft + root->val, gainFromRight + root->val);
    }
};