// #0559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/


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


// Approach 1: Recursion
// N is the number of nodes
// Time complexity: O(N), Space complexity: O(log(N)) for balance tree (worst case - O(N))
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int levelDepth = 0;
        for(auto child: root->children){
            levelDepth = max(levelDepth, maxDepth(child));
        }
        return levelDepth + 1;
    }
};


// Approach 2: Iteration
// Time complexity: O(N), Space complexity: O(N)
// Iterative DFS
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;

        stack<pair<Node*, int>> stk;
        stk.push({root, 1});
        int depth = 0;

        while (!stk.empty()) {
            auto [currNode, currDepth] = stk.top();
            stk.pop();
            depth = max(depth, currDepth);
            for (Node* child : currNode->children) {
                if (child != nullptr) {
                    stk.push({child, currDepth + 1});
                }
            }
        }

        return depth;
    }
};

// Iterative BFS
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;

        queue<pair<Node*, int>> q;
        q.push({root, 1});
        int depth = 0;

        while (!q.empty()) {
            auto [node, current_depth] = q.front();
            q.pop();
            depth = max(depth, current_depth);
            for (Node* child : node->children) {
                q.push({child, current_depth + 1});
            }
        }

        return depth;
    }
};
