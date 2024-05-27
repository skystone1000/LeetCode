// #0429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Approach 1: Breadth-first Search using a Queue
// Time complexity : O(n), Space complexity : O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (Node* child : node->children) {
                    q.push(child);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};



// Approach 2: Simplified Breadth-first Search (without queue)
// Time complexity : O(n), Space complexity : O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        vector<Node*> currentLayer{root};

        while (!currentLayer.empty()) {
            vector<Node*> nextLayer;
            vector<int> currentValues;

            for (Node* node : currentLayer) {
                currentValues.push_back(node->val);
                for (Node* child : node->children) {
                    nextLayer.push_back(child);
                }
            }

            result.push_back(currentValues);
            currentLayer = nextLayer;
        }

        return result;
    }
};



// Approach 3: Recursion (DFS)
// Time complexity : O(n), Space complexity : O(logn)
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> levelOrder(Node* root) {
        if (root) dfs(root, 0);
        return result;
    }

    void dfs(Node* node, int level) {
        if (result.size() <= level) {
            result.push_back({});
        }

        result[level].push_back(node->val);

        for (Node* child : node->children) {
            dfs(child, level + 1);
        }
    }
};
