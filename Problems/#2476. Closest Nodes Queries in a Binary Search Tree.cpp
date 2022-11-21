// #2476. Closest Nodes Queries in a Binary Search Tree
// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/

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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inOrd;
        inOrderTrav(root, inOrd);
        
        vector<vector<int>> ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i] < inOrd[0]){
                ans.push_back({-1,inOrd[0]});
                continue;
            }
            if(queries[i] > inOrd[inOrd.size()-1]){
                ans.push_back({inOrd[inOrd.size()-1],-1});
                continue;
            }
            
            int curr = lower_bound(inOrd.begin(),inOrd.end(), queries[i]) - inOrd.begin();
            if(inOrd[curr] == queries[i]){
                ans.push_back({inOrd[curr],inOrd[curr]});
            }else {
                ans.push_back({inOrd[curr-1], inOrd[curr]});
            }
        }
        return ans;
    }
    
    void inOrderTrav(TreeNode* root, vector<int>& inOrd){
        if(root == NULL)
            return;
        
        inOrderTrav(root->left, inOrd);
        inOrd.push_back(root->val);
        inOrderTrav(root->right, inOrd);
    }
};