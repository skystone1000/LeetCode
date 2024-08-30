// #0104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// Company Tag - Amazon - number 28
// Binary Tree 05

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

// Approach 1: Recursion
// N is the number of nodes.
// Time complexity: O(N), Space complexity: O(log(N)) for balance tree (worst case - O(N))

// Bottom Up Approach (Post Order Traversal)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left_depth = maxDepth(root -> left);
        int right_depth = maxDepth(root -> right);
        return max(left_depth, right_depth) + 1;
    }
};

// Top Down Approach (Pre Order Traversal)
class Solution2 {
public:
    int answer=0;
    int maxDepth(TreeNode* root) {
        calDepth(root,1);
        return answer;
    }
    
    void calDepth(TreeNode* root, int depth){
        if(root == nullptr) return; 
        
        if(root->left == nullptr && root->right == nullptr){
            answer = max(answer,depth);
        }
        
        calDepth(root->left,depth+1);
        calDepth(root->right,depth+1);
    }
};



// Approach 2: Tail Recursion + BFS
// Time complexity: O(N), Space complexity: O(N)
class Solution {
private:
    // The queue that contains the next nodes to visit,
    // along with the level/depth that each node is located.
    queue<pair<TreeNode*, int>> next_items;
    int max_depth = 0;

    
    // A tail recursion function to calculate the max depth of the binary tree.
     
    int next_maxDepth() {

        if (next_items.size() == 0) {
            return max_depth;
        }

        auto next_item = next_items.front();
        next_items.pop();

        auto next_node = next_item.first;
        auto next_level = next_item.second + 1;

        max_depth = max(max_depth, next_level);

        // Add the nodes to visit in the following recursive calls.
        if (next_node->left != NULL) {
            next_items.push(make_pair(next_node->left, next_level));
        }
        if (next_node->right != NULL) {
            next_items.push(make_pair(next_node->right, next_level));
        }

        // The last action should be the ONLY recursive call
        // in the tail-recursion function.
        return next_maxDepth();
    }

public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        // Clear the previous queue.
        queue<pair<TreeNode*, int>> empty;
        swap(next_items, empty);
        max_depth = 0;

        // Push the root node into the queue to kick off the next visit.
        next_items.push(make_pair(root, 0));

        return next_maxDepth();
    }
};


// Approach 3: Iteration
// Time complexity: O(N), Space complexity: O(log(N)) for balance tree (worst case - O(N))
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        vector<pair<int, TreeNode*>> myStack;
        myStack.push_back(pair<int, TreeNode*>(1, root));
        int maxDepth = 0;
        while (!myStack.empty()) {
            pair<int, TreeNode*> my_pair = myStack.back();
            int currDepth = get<0>(my_pair);
            TreeNode* currNode = get<1>(my_pair);
            maxDepth = max(maxDepth, currDepth);
            myStack.pop_back();
            if (currNode->left != NULL) {
                myStack.push_back(
                    pair<int, TreeNode*>(currDepth + 1, currNode->left));
            }
            if (currNode->right != NULL) {
                myStack.push_back(
                    pair<int, TreeNode*>(currDepth + 1, currNode->right));
            }
        }
        return maxDepth;
    }
};