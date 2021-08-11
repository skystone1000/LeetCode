// Binary Search Tree
// 01 #0098 Validate Binary Search Tree

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
    vector<int> inOrd;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        // Get In order Traversal
        inOrdCheck(root);
        
        // Check if it is sorted
        // bool ans = is_sorted(inOrd.begin(),inOrd.end());
        bool ans = true;
        for(int i=0;i<inOrd.size()-1;i++){
            if(inOrd[i] < inOrd[i+1]){
                continue;
            }else{
                ans = false;
                break;
            }
        }
        
        return ans;
    }
    
    void inOrdCheck(TreeNode* root) {
        if(root == nullptr) return;
    
        inOrdCheck(root->left);
        inOrd.push_back(root->val);
        inOrdCheck(root->right);
    }
};