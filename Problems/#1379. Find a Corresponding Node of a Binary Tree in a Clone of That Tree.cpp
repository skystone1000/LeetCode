// #1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// Runtime: 547 ms, faster than 88.12% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
// Memory Usage: 163.8 MB, less than 95.67% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    TreeNode* copyNode;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inOrd(original, cloned, target);
        return copyNode;
    }
    
    void inOrd(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == NULL){
            return;
        }
        
        if(original == target){
            copyNode = cloned;
            return;
        }
        
        inOrd(original->left, cloned->left, target);
        inOrd(original->right, cloned->right, target);
    }
};