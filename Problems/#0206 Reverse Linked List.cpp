// Company Amazon
// 08 #0206 Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// Method 1 - O(N) Space Stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        
        stack<ListNode*> st;
        while(head != NULL){
            ListNode* temp = head;
            st.push(head);
            head = head->next;
            temp->next = NULL;
        }
        
        ListNode dummy(0);
        ListNode *temp = &dummy;
        while(!st.empty()){
            temp->next = st.top();
            temp=temp->next;
            st.pop();
        }
        return dummy.next;
    }
};

// Method 2 - Interative
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

// Method 2 - Recursive
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