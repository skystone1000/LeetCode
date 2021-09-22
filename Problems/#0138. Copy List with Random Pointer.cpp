// Company Amazon
// AIE 3.6 #0138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Creating copy of all nodes just after that node
        for(Node* itr=head; itr != NULL; itr = itr->next->next){
            Node* newNode = new Node(itr->val);
            newNode->next = itr->next;
            itr->next = newNode;
        }
        
        // Updating random pointers
        for(Node* itr=head; itr != NULL; itr = itr->next->next){
            if(itr->random != NULL){
                // itr->next (newNode)  ---  itr->random (old Node's random)
                itr->next->random = itr->random->next;
            }
        }
        
        Node dummy(-1);
        for(Node* itr=head, *itr_copy=&dummy ; 
            itr != NULL ; 
            itr = itr->next, itr_copy = itr_copy->next){
            itr_copy->next = itr->next;
            itr->next = itr->next->next;
        }
        
        return dummy.next;
    }
};