// Binary Search Tree
// 03 #0173 Binary Search Tree Iterator

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
class BSTIterator {
    vector<int> inOrdEle;
    int pos;
public:
    BSTIterator(TreeNode* root) {
        inOrd(root);
        pos = 0; 
    }
    
    void inOrd(TreeNode* root){
        if(root == NULL) return;
        
        inOrd(root->left);
        inOrdEle.push_back(root->val);
        inOrd(root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        int nextSmall = inOrdEle[pos];
        pos++;
        return nextSmall;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(pos < inOrdEle.size()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */