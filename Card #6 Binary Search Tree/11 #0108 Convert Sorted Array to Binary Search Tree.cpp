// Binary Search Tree
// 11 #0108 Convert Sorted Array to Binary Search Tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return constructBSTRecursive(nums, 0, nums.size()-1);
    }

    TreeNode* constructBSTRecursive(vector<int> &nums, int left, int right){
        if(left > right) return NULL;

        int mid = left + (right-left)/2;
        TreeNode* current = new TreeNode(nums[mid]);
        current->left = constructBSTRecursive(nums, left, mid-1);
        current->right = constructBSTRecursive(nums, mid+1, right);
        return current;
    }
    
};