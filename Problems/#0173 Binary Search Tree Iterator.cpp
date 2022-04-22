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

// Method 2 - Space - O(height of tree), avg query time - O(1)
// Runtime: 40 ms, faster than 46.66% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.1 MB, less than 87.61% of C++ online submissions for Binary Search Tree Iterator.
class BSTIterator {
    stack<TreeNode*> myStack; 
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();      
    }
    
    void pushAll(TreeNode* node){
        while(node != NULL){
            myStack.push(node);
            node = node->left;
        }
    }
};


// Method 1 - Space - O(n), avg query time - O(1) 
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