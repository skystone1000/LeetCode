// Linked List 07
// #0203 Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        while(head != NULL && head ->val == val){
            head = head ->next;
        }
        if(head == NULL) return NULL;
        ListNode* curr = head ->next;
        ListNode* prev= head;
        while(curr != NULL){
            if(curr -> val == val){
                prev->next = curr->next;
                curr = curr -> next;
            }
            else{
                prev = prev ->next;                
                curr = curr -> next;
            }
        }
        
        return head;
    }
};