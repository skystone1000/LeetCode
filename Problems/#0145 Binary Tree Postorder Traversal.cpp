// Binary Tree
// AIE 6.5 #0145 Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

// One Stack Solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack1;
        vector<int> postOrd;
        if(root)
            stack1.push(root);
        while(stack1.size() > 0){
            TreeNode* curr = stack1.top();
            stack1.pop();
            postOrd.push_back(curr->val);
            if(curr->left != NULL){
                stack1.push(curr->left);
            }
            if(curr->right != NULL){
                stack1.push(curr->right);
            }
        }
        
        reverse(postOrd.begin(),postOrd.end()); // Trick
        return postOrd;
    }
};

/* 
// Iterative
// Two Stacks Solution - Time - O(n)  Space - O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        if(root)
            stack1.push(root);
        while(stack1.size() > 0){
            TreeNode* curr = stack1.top();
            stack1.pop();
            stack2.push(curr);
            if(curr->left != NULL){
                stack1.push(curr->left);
            }
            if(curr->right != NULL){
                stack1.push(curr->right);
            }
        }
        
        vector<int> postOrd;
        while(stack2.empty() != true){
            postOrd.push_back(stack2.top()->val);
            stack2.pop();
        }
        
        return postOrd;
    }
};*/

/* 
// Time - O(n)  Space - O(n) (Stack frame of recursive call)
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        postOrd(root);
        return ans;
    }
    
    void postOrd(TreeNode *root){
        if(root == NULL){
            return;
        }
        
        postOrd(root->left);
        postOrd(root->right);
        ans.push_back(root->val);
    }
};
*/