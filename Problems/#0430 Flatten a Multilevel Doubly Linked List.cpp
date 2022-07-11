// Linked List 13
// 13 #0430 Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// Method 1 - Simple approach
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return head;
        
        Node* node = head;
        while(node != NULL){
            if(node->child != NULL){
                // Initial pointer updates
                Node* saveNext = node->next;
                node->child->prev = node;
                node->next = flatten(node->child);
                node->child = NULL;
                
                // Iterating till Last
                while(node->next != NULL)
                    node = node->next;
                
                // Final pointer updates
                node->next = saveNext;
                if(saveNext != NULL)
                    saveNext->prev = node;
                
            }
            node = node->next;
            
        }
        
        return head;
    }
};

// Method 2 - 5 line
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/295912/C%2B%2B-Simple-5-line-recursive-solution-(with-diagram) 
Node* flatten(Node* head, Node* rest = nullptr) {
    if (!head) return rest;
    head->next = flatten(head->child, flatten(head->next, rest));
    if (head->next) head->next->prev = head;
    head->child = nullptr;
    return head;
}