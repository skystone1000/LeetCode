// Linked List 09
// 09 #0234 Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

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

// Time - O(n), Space - O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int nodes = 0;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            nodes++;
        }
        
        ListNode* revHead = reverseList(slow);
        
        for(int i=0;i<nodes;i++){
            if(head->val != revHead->val)
                return false;
            head = head->next;
            revHead = revHead->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = head;
        
        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
};


// Extra space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        vector<int> start;
        ListNode* iter = head;
        while(iter != NULL){            
            start.push_back(iter->val);
            iter = iter -> next;
        }
        
        int p1 = 0,p2 = start.size()-1;
        while(p1<=p2){
            if(start[p1] != start[p2]){
                return false;
            }
            p1++;p2--;
        }
        return true;
    }
};