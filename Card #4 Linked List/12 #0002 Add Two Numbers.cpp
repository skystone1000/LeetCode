// Linked List 12
// 12 #0002 Add Two Numbers

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