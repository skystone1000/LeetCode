// Company Amazon
// Linked List 12
// 06 #0002 Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

#include<bits/stdc++.h>
using namespace std;

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
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

// Iterative
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse the LL if the number are not.
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        
        int carry = 0;
        while(l1 || l2 || carry){
            int a=0,b=0;
            if(l1) a = l1->val; // Same as checking if(l1!=NULL)
            if(l2) b = l2->val;
            
            int sum = a + b + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            curr = curr->next;
        }
        return dummy.next;
    }
};

// Recursive solution
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return helper(l1, l2, 0);
	}

	ListNode* helper(ListNode* l1, ListNode* l2, int carry) {
		if (!l1 && !l2 && !carry) {
			return NULL;
		}
        
        int a=0,b=0;
        if(l1) a = l1->val; // Same as checking if(l1!=NULL)
        if(l2) b = l2->val;
        
		int sum = a + b + carry;
		ListNode* curr = new ListNode(sum % 10);
        carry = sum / 10;
        
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
		curr->next = helper(l1, l2, carry);
		return curr;
	}
};