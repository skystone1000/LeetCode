// Company Amazon
// Linked List 12
// 06 #0002 Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

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
}

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* headA, ListNode* headB){
        // reverse the LL if the number are not.

        ListNode dummy(-1);
        ListNode* curr = &dummy; 

        int carry = 0;
        while(headA || headB || carry){
            int a = headA != NULL ? headA->val : 0;
            int b = headB != NULL ? headB->val : 0;

            int sum = a + b + carry;

            curr->next = new ListNode(sum % 10); 
            int carry = sum / 10;

            headA = headA != NULL ? headA->next : NULL;
            headB = headB != NULL ? headB->next : NULL;
            curr = curr->next;
        }

        return dummy.next;
    }
};