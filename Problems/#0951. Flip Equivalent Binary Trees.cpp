// #0951. Flip Equivalent Binary Trees
// https://leetcode.com/problems/flip-equivalent-binary-trees/description/
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

// Approach 3: Canonical Forms
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    void findCanonicalForm(TreeNode* root) {
        if (!root) return;

        // Post-order traversal: first bring subtrees in their canonical form
        findCanonicalForm(root->left);
        findCanonicalForm(root->right);

        if (!root->right) return;
        // Swap subtrees, so that left is non-empty
        if (!root->left) {
            root->left = root->right;
            root->right = NULL;
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // Swap subtrees
        if (left->val > right->val) {
            root->left = right;
            root->right = left;
        }
    }

    bool areEquivalent(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return areEquivalent(root1->left, root2->left) &&
                areEquivalent(root1->right, root2->right);
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);
        return areEquivalent(root1, root2);
    }
};


// Approach 2: Iterative DFS (using a Stack)
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    // Checks whether the given pair of nodes should be examined -
    // be pushed into the stack
    bool checkNodeValues(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 && node2 && node1->val == node2->val) return true;
        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Initialize stack to store pairs of nodes
        stack<pair<TreeNode*, TreeNode*>> nodePairStack;
        nodePairStack.push({root1, root2});

        // While the stack is not empty:
        while (!nodePairStack.empty()) {
            auto [node1, node2] = nodePairStack.top();
            nodePairStack.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;

            // Check both configurations: no swap and swap
            if (checkNodeValues(node1->left, node2->left) &&
                checkNodeValues(node1->right, node2->right)) {
                nodePairStack.push({node1->left, node2->left});
                nodePairStack.push({node1->right, node2->right});
            } else if (checkNodeValues(node1->left, node2->right) &&
                        checkNodeValues(node1->right, node2->left)) {
                nodePairStack.push({node1->left, node2->right});
                nodePairStack.push({node1->right, node2->left});
            } else {
                return false;
            }
        }
        return true;
    };
};


// Approach 1: Recursion (Top-down Traversal)
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Both trees are empty
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // Just one of the trees is empty
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        // Corresponding values differ
        if (root1->val != root2->val) {
            return false;
        }

        // Check if corresponding subtrees are flip equivalent
        bool noSwap = flipEquiv(root1->left, root2->left) &&
                        flipEquiv(root1->right, root2->right);
        // Check if opposite subtrees are flip equivalent
        bool swap = flipEquiv(root1->left, root2->right) &&
                    flipEquiv(root1->right, root2->left);

        return swap || noSwap;
    }
};
