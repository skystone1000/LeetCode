// Company Amazon
// AIE 7.3 #0099. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/

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
class Solution {
    TreeNode* firstStartPoint, *lastEndPoint, *prevNode;
public:
    void recoverTree(TreeNode* root) {
        findSegments(root);
        swap(firstStartPoint->val, lastEndPoint->val);
    }
    
    void findSegments(TreeNode* root){
        if(root == NULL) return;
        findSegments(root->left);
        if(prevNode != NULL){
            if(prevNode->val > root->val){
                if(firstStartPoint == NULL){
                    firstStartPoint = prevNode;
                }
                lastEndPoint = root;
            }
        }
        prevNode = root;
        findSegments(root->right);
    }
};


// Method 2 - O(n) space
// Runtime: 27 ms, faster than 91.61% of C++ online submissions for Recover Binary Search Tree.
// Memory Usage: 58.1 MB, less than 28.70% of C++ online submissions for Recover Binary Search Tree.
class Solution {
    vector<int> inOrdTrav;
public:
    void recoverTree(TreeNode* root) {
        inOrd(root);
        sort(inOrdTrav.begin(),inOrdTrav.end());
        int i=0;
        recover(root, i);
    }
    
    void inOrd(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        inOrd(root->left);
        inOrdTrav.push_back(root->val);
        cout<<root->val<<" ";
        inOrd(root->right);
    }
    
    void recover(TreeNode* root, int &i){
        if(root == NULL){
            return;
        }
        
        recover(root->left, i);
        if(root->val != inOrdTrav[i]){
            root->val = inOrdTrav[i];
        }
        i++;
        recover(root->right, i);
    }
};