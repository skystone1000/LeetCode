// Linked List 05
// #0019 Remove Nth Node From End of List

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head==NULL || n<=0){
            return NULL;
        }
        ListNode fakeHead(0);
        fakeHead.next=head;
        head=&fakeHead;
        
        ListNode *p1, *p2;
        p1=p2=head;
        for(int i=0; i<n; i++){
            if (p2==NULL) return NULL;
            p2=p2->next;
        }
        while (p2->next!=NULL){
            p2=p2->next;
            p1=p1->next;
        }
        
        p1->next = p1->next->next;
        return head->next;
    }
};

/* Check what is going wrong
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        
        int nodes = 0;
        ListNode* iter = head;
        while(iter != NULL){
            iter = iter -> next;
            nodes++;
        }
        int toRem = nodes - n;
        cout<<"rem = "<<toRem;
        iter = head;
        for(int i=0;i<toRem-1;i++){
            iter = iter -> next;
        }
        
        if(iter == head){
            head = head->next;
        }else{
            iter -> next = iter -> next -> next;
        }
        return head;
    }
};*/