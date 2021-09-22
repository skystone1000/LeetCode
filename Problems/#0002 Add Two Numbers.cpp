// Company Amazon
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;
        
        int carry = 0;
        while(l1 || l2 || carry){
            int a = l1 ? l1->val:0;
            int b = l2 ? l2->val:0;
            int val = carry + a + b;
            
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            curr = curr->next;
        }
        
        return dummy.next;
    }
};