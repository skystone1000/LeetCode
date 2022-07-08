// Company Amazon
// 37 #0021. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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

// Recursive - approach 2
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;
		
		if(l1 -> val <= l2 -> val){
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		} else {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	


// Iterative - Approach 1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* head = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            }else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        head->next = l1 != NULL ? l1:l2;
        return dummy.next;
        
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* itr = dummy;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                itr->next = l1;
                l1 = l1->next;
            } else{
                itr->next = l2;
                l2 = l2->next;
            }
            itr = itr->next;
        }
        
        if(l1 != NULL){
            itr->next = l1;
        }
        if(l2 != NULL){
            itr->next = l2;
        }
        return dummy->next;
    }
};