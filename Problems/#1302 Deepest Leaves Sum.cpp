// April Challenge 2021 - Day 11
// #1302 Deepest Leaves Sum

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        
        int level_sum = 0;
        while(!qu.empty()){
            level_sum = 0;
            
            int currSize = qu.size();
            for(int i=0;i<currSize;i++){
                TreeNode* current_node = qu.front();
                qu.pop();
                level_sum += current_node -> val;
                
                if(current_node->left != NULL)
                    qu.push(current_node->left);
                if(current_node->right != NULL)
                    qu.push(current_node->right);
            }
        }
        
        return level_sum;
    }
};