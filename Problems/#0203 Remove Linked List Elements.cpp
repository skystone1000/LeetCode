// Linked List 07
// #0203 Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        while(head != NULL && head ->val == val){
            head = head ->next;
        }
        if(head == NULL) return NULL;
        ListNode* iterator = head ->next;
        ListNode* prev= head;
        while(iterator != NULL){
            if(iterator -> val == val){
                prev->next = iterator->next;
                iterator = iterator -> next;
            }
            else{
                prev = prev ->next;                
                iterator = iterator -> next;
            }
        }
        
        return head;
    }
};