// Company Amazon
// 53 #0572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

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

// Approach 1: Recursive Comparision
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL){
            return false;
        }else if(isSameTree(s,t)){
            return true;
        }else{
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
    
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL){
            // Case when both node are NULL
            return true;
        } else if(s == NULL || t == NULL){
            // Case when either s or t is NULL (Here both cant be null as check earlier)
            return false;
        } else if(s->val == t->val){
            // Now if values are same check the remaining if same
            return isSameTree(s->right, t->right) && isSameTree(s->left, t->left);
        } else {
            return false;
        }
    }
};

// Approach 2: Take preOrder of both and check if t is substring of s
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string tree1 = preOrder(s, true);
        string tree2 = preOrder(t, true);
        
        string::size_type loc = tree1.find( tree2, 0 );
        return loc != string::npos ? true : false;
        /*
        if( loc != string::npos ) {
            return true;
        } else {
            return false;
        }
        */
    }
    
    string preOrder(TreeNode* t, bool left) {
        if(t == NULL){
            if(left)
                return "lnull";
            else 
                return "rnull";
        }
        return "#" + to_string(t->val) + " " + preOrder(t->left, true) + " " + preOrder(t->right, false);
    }
};