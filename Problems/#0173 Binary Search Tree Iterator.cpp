// Binary Search Tree
// 03 #0173 Binary Search Tree Iterator

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

// Method 1
// Runtime: 37 ms, faster than 56.32% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.4 MB, less than 10.53% of C++ online submissions for Binary Search Tree Iterator.
class BSTIterator {
    vector<int> inOrd;
    int ptr;
public:
    BSTIterator(TreeNode* root) {
        traverse(root);
        ptr = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        if(ptr<inOrd.size()){
            int val = inOrd[ptr];
            ptr++;
            return val;
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(ptr<inOrd.size())
            return true;
        else 
            return false; 
    }
    
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        traverse(root->left);
        inOrd.push_back(root->val);
        traverse(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */