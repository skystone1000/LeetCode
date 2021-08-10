// Binary Tree
// 04 #102 Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL){
            return result;
        }
        
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        
        while(!myqueue.empty()){
            vector <int> currentLevel;
            int n = myqueue.size();
            
            for(int i=0;i<n;i++){
                TreeNode *currentNode = myqueue.front();
                currentLevel.push_back(currentNode->val);
                myqueue.pop();
                
                if(currentNode -> left != NULL){
                    myqueue.push(currentNode -> left);
                }
                if(currentNode -> right != NULL){
                    myqueue.push(currentNode -> right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};