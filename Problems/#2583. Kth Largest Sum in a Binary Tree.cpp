// #2583. Kth Largest Sum in a Binary Tree
// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;

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
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL)
            return -1;

        queue<TreeNode*> q;
        q.push(root);

        priority_queue<long> pq;
        while(!q.empty()){
            long long levelsum = 0;
            long long n = q.size();
            for(long long i=0;i<n;i++){
                TreeNode* currNode = q.front();
                levelsum += currNode->val;
                q.pop();

                if(currNode->left != NULL)
                    q.push(currNode->left);
                
                if(currNode->right != NULL)
                    q.push(currNode->right);
            }

            pq.push(levelsum);
        }

        if(k>pq.size())
            return -1;
        
        for (int i = 0; i < k - 1; i++) 
            pq.pop();
        return pq.top();
    }
};