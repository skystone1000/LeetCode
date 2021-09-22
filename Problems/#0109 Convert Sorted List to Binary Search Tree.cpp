// May Challenge 2021 - Day 6 - #0109. Convert Sorted List to Binary Search Tree
// #0109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* midEle = mid(head);
        TreeNode* root = new TreeNode(midEle->val);
        
        if(head == midEle)
            return root;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(midEle->next);
        return root;
    }
    
    ListNode* mid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(prev != NULL)
            prev -> next = NULL;
        
        return slow;
    }
};