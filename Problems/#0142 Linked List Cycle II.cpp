// Linked List 03
// #0142 Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *fast;
    ListNode *slow;
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;

        fast = head;
        slow = head;
        while(fast != NULL && fast ->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    } 
    
    /* 
     * So, the idea is:
     *   1) Using the cycle-chcking algorithm.
     *   2) Once slow and slow meet, then reset slow to head, and move slow & fast synchronously
     *      until slow and fast meet again, that place is the cycle's start-point 
     */
    ListNode *detectCycle(ListNode *head) {
        if (hasCycle(head)==false){
            return NULL;
        }
        slow = head;
        while (slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};