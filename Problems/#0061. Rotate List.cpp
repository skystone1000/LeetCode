// Linked List 16
// #0061. Rotate List
// https://leetcode.com/problems/rotate-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<1)
            return head;
        
        ListNode* origHead = head;
        ListNode* newHead;
        ListNode* origTail;
        ListNode* newTail;
        
        // Getting total nodes
        int nodes = 1;
        ListNode* itr = head;
        while(itr->next != NULL){
            itr = itr->next;
            nodes++;
        }
        
        // Updating tail;
        origTail = itr;
        k = k % nodes;
        if(k == 0) return origHead;
        itr = origHead;
        for(int i=0;i<nodes-k-1;i++){
            itr = itr->next;
        }
        
        // Updating new head and tail
        newTail = itr;
        newHead = itr->next;
        
        // Final Linking
        newTail->next = NULL;
        origTail->next = origHead;
        return newHead;
    }
};