// Company Amazon
// 49 #0098. Validate Binary Search Tree
// Binary Search Tree 01
// https://leetcode.com/problems/validate-binary-search-tree/

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
    vector<int> inOrd;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        // Get In order Traversal
        inOrdCheck(root);
        
        // Check if it is sorted
        // bool ans = is_sorted(inOrd.begin(),inOrd.end());
        bool ans = true;
        for(int i=0;i<inOrd.size()-1;i++){
            if(inOrd[i] < inOrd[i+1]){
                continue;
            }else{
                ans = false;
                break;
            }
        }
        
        return ans;
    }
    
    void inOrdCheck(TreeNode* root) {
        if(root == nullptr) return;
    
        inOrdCheck(root->left);
        inOrd.push_back(root->val);
        inOrdCheck(root->right);
    }
};

/*
// Check what is wrong in below solution
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
    
    bool validate(TreeNode* root, int maxVal, int minVal){
        if(root == NULL) {
            return true;
        } else if(maxVal != NULL && root->val >= maxVal || minVal != NULL && root->val <= minVal){
            return false;
        } else {
            return validate(root->left, root->val, minVal) && validate(root->right, maxVal, root->val);
        }
    }
};
*/