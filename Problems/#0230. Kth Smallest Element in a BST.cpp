// #0230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Priority Queue PreOrder traversal 
// Runtime: 24 ms, faster than 54.71% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 24.5 MB, less than 16.05% of C++ online submissions for Kth Smallest Element in a BST.
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
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    int kthSmallest(TreeNode* root, int k) {
        preOrder(root);
        
        int i=0;
        while(!minHeap.empty()){
            if(i == k-1){
                return minHeap.top();
            }
            minHeap.pop();
            i++;
        }
        return minHeap.top();
    }
    
    void preOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        minHeap.push(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};