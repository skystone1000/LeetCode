// #0222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/description/
// Company Tag - Google

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


// Approach 1: Linear Time
// Time complexity : O(N).
// Space complexity : O(d)=O(logN) to keep the recursion stack, where d is a
// tree depth.
class Solution {
public:
    int countNodes(TreeNode* root) {
        // Base case: if the root is null, return 0
        if (root == nullptr) return 0;

        // Recursively count: 1 (current node) + left subtree + right subtree
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


// Approach 2: Binary search
// Time complexity : O(d^2)=O(logN)^2,where d is a tree depth.
// Space complexity : O(1)

class Solution {
public:
    // Function to compute the tree depth (leftmost path)
    int computeDepth(TreeNode* node) {
        int d = 0;
        while (node->left != nullptr) {
            node = node->left;
            ++d;
        }
        return d;
    }

    // Function to check if a node exists at index idx in the last level
    bool exists(int idx, int d, TreeNode* node) {
        int left = 0, right = static_cast<int>(pow(2, d)) - 1;  // total nodes at last level: 2^d
        int pivot;
        for (int i = 0; i < d; ++i) {
            pivot = left + (right - left) / 2;
            if (idx <= pivot) {
                node = node->left;
                right = pivot;
            } else {
                node = node->right;
                left = pivot + 1;
            }
        }
        return node != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int d = computeDepth(root);
        if (d == 0) return 1;

        int left = 1, right = static_cast<int>(pow(2, d)) - 1; // Nodes in last level range
        int pivot;

        // Binary search to find how many nodes exist on the last level
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (exists(pivot, d, root)) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }

        // Total nodes = nodes above last level + existing nodes in last level
        return static_cast<int>(pow(2, d)) - 1 + left;
    }
};
    