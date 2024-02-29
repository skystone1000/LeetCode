// #0106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Company Tag - Amazon, google

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
 

class Solution {
    int postOrderIndex;
    vector<int> postorder;
    vector<int> inorder;
    unordered_map<int, int> postOrderIndexMap;

public:
    TreeNode* helper(int left, int right) {
        if (left > right)
            return NULL;

        int root_val = postorder[postOrderIndex];
        TreeNode* root = new TreeNode(root_val);

        int index = postOrderIndexMap[root_val];
        postOrderIndex--;

        root->right = helper(index + 1, right);
        root->left = helper(left, index - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        this->inorder = inorder;

        postOrderIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) 
            postOrderIndexMap[inorder[i]] = i;

        return helper(0, inorder.size() - 1);
    }
};