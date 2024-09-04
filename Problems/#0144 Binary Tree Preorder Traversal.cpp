// Binary Tree 01
// 01 #0144 Binary Tree Preorder Traversal

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root){
        preOrder(root);
        return ans;
    }

    void preOrder(TreeNode *root){
        if (root == NULL){
            return;
        }

        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};


// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();
        }

        vector<TreeNode*> stack = {root};
        vector<int> output;

        while (!stack.empty()) {
            root = stack.back();
            stack.pop_back();
            if (root != nullptr) {
                output.push_back(root->val);
                if (root->right != nullptr) {
                    stack.push_back(root->right);
                }
                if (root->left != nullptr) {
                    stack.push_back(root->left);
                }
            }
        }

        return output;
    }
};