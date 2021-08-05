// Company Amazon
// 15 #0206 Reverse Linked List
// 


// Stack solution remaining












class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* reversedListHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversedListHead;
    }
};