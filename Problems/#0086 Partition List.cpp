// April Challenge 2021 - Day 14
// #0086. Partition List

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // List Before the element x
        ListNode beforeHead(-1);
        ListNode* before = &beforeHead;
        
        // List After the element x 
        ListNode afterHead(-1);
        ListNode* after = &afterHead;
        
        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            } else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        // Denoting the end of list
        after->next = NULL;
        // Merging 2 Lists
        before->next = afterHead.next;
        
        return beforeHead.next;
    }
};