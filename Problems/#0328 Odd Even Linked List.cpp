// Linked List 08
// #0328 Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        
        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }     
};

// Inefficient and difficult to understand
class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *even = head;
        int counter = 0;
        while(even -> next){
            even = even->next;
            counter += 1;
        }
        
        counter = counter & 1 ? (counter/2)+1 : counter/2;
        ListNode *start = head;
        while(counter--){
            even->next = start->next;
            start->next = start->next->next;
            even->next->next = NULL;
            start = start->next;
            even = even ->next;
        }
        
        return head;
    }
};