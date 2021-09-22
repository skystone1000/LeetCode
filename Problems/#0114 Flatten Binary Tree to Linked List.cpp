// May Challenge 2021 - Day 14
// #0114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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

// Method 3 (Effiecient - Morris traversal)
// Time - O(n)
// Space - O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* prev = curr->left;
                while(prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

/*
// Method 2 (Iterative - Reverse PostOrder)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* curr = st.top(); st.pop();
            if(curr->right != NULL)
                st.push(curr->right);
            if(curr->left != NULL)
                st.push(curr->left);
            if(!st.empty())
                curr->right = st.top();
            curr->left = NULL;
        }
    }
};

// Method 1 (Recursive - Reverse PostOrder)
class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

*/