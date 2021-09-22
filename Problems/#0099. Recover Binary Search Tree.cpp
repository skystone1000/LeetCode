// Company Amazon
// AIE 7.3 #0099. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode* firstStartPoint, *lastEndPoint, *prevNode;
public:
    void recoverTree(TreeNode* root) {
        findSegments(root);
        swap(firstStartPoint->val, lastEndPoint->val);
    }
    
    void findSegments(TreeNode* root){
        if(root == NULL) return;
        findSegments(root->left);
        if(prevNode != NULL){
            if(prevNode->val > root->val){
                if(firstStartPoint == NULL){
                    firstStartPoint = prevNode;
                }
                lastEndPoint = root;
            }
        }
        prevNode = root;
        findSegments(root->right);
    }
};