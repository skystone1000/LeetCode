// April Challenge 2021 - Day 18
// #0019. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head==NULL || n<=0){
            return NULL;
        }
        ListNode dummy(0);
        dummy.next=head;
        head=&dummy;
        
        ListNode *p, *q;
        p=q=head;
        for(int i=0; i<n; i++){
            if (p==NULL) return NULL;
            p=p->next;
        }
        while (p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        
        q->next = q->next->next;
        return head->next;
    }
};

/* 
// Approach 1 - Two Pass 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode dummy(-1);
        dummy.next = head;
        head = &dummy;
        
        int  total = 0;
        ListNode* itr = head;
        while(itr->next != NULL){
            itr = itr->next;
            total++;
        }

        
        int k = total - n;
        itr = head;
        for(int i=0;i<k;i++){
            itr = itr->next;
        }
        
        itr->next = itr->next->next;
        return dummy.next;
    }
};
*/