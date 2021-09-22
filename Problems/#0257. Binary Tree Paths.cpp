// Company Amazon
// 42 #0257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL) return paths;
        
        findPaths(root, "", paths);
        return paths;
    }
    
    void findPaths(TreeNode* root, string curr, vector<string>& paths){
        if(root == NULL)
            return ;
        
        curr += to_string(root->val);
        if(root->right == NULL && root->left == NULL){
            paths.push_back(curr);
        }
        
        findPaths(root->right, curr+"->", paths);
        findPaths(root->left, curr+"->", paths);
    }
};


// Wee Need to check NULL for both right and left if we 
// Do not give base condition (root == NULL)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL) return paths;
        
        findPaths(root, "", paths);
        return paths;
    }
    
    void findPaths(TreeNode* root, string curr, vector<string>& paths){
        curr += to_string(root->val);
        if(root->right == NULL && root->left == NULL){
            paths.push_back(curr);
        }
        
        if(root->right != NULL){
            findPaths(root->right, curr+"->", paths);
        } 
        if(root->left != NULL){
            findPaths(root->left, curr+"->", paths);
        }
    }
};