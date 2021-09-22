// Company Amazon
// 44 #0160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        while(p1 != p2 ){
            if(p1 == NULL){
                p1 = headB;
            } else {
                p1 = p1->next;                
            }
            
            if(p2 == NULL){
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        return p1;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> visited;
        
        while(headA != NULL){
            visited.insert(headA);
            headA = headA->next;
        }
        
        while(headB != NULL){
            if(visited.count(headB) > 0){
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    }
};