// Company Amazon
// 39 #0199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(root == NULL) return rightView;
         
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(!qu.empty()){
            int n = qu.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = qu.front();
                if(i == n-1){
                    rightView.push_back(curr->val);
                }
                if(curr->left != NULL){
                    qu.push(curr->left);
                }
                if(curr->right != NULL){
                    qu.push(curr->right);
                }
                qu.pop();
            }
        }
        return rightView;
    }
};