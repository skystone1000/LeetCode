// #0116. Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        Node* leftNode = root;
        while(leftNode != NULL && leftNode->left != NULL){
            populateLowerLevel(leftNode);
            leftNode = leftNode->left;
        }
        return root;
    }
    
    void populateLowerLevel(Node* startNode){
        Node* iter = startNode;
        while(iter != NULL){
            iter->left->next = iter->right;
            if(iter->next != NULL)
                iter->right->next = iter->next->left;
            iter = iter->next;
        }
    }
};