// #0543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
// Company Tag - AIE 12.2 Amazon, Meta, Google

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

// Approach 1: Depth-first Search
// Time complexity: O(N), Space complexity: O(N)
class Solution {
private:
    int diameter;

    int longestPath(TreeNode* node) {
        if (node == nullptr) return 0;

        // Recursively find the longest path in both left and right children
        int leftPath = longestPath(node->left);
        int rightPath = longestPath(node->right);

        // Update the diameter if leftPath + rightPath is greater
        diameter = std::max(diameter, leftPath + rightPath);

        // Return the longest one between leftPath and rightPath + 1
        return std::max(leftPath, rightPath) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
};


// Old Approach
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
