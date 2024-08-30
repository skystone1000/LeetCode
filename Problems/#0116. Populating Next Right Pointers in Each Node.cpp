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


// Approach 2: Using previously established next pointers
// Time Complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        Node* leftmost = root;
        while (leftmost->left != nullptr) {
            Node* head = leftmost;
            while (head != nullptr) {
                // CONNECTION 1
                head->left->next = head->right;
                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};



// Approach 1: Level Order Traversal (BFS)
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> Q;
        Q.push(root);
        while (Q.size() > 0) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                Node* node = Q.front();
                Q.pop();
                if (i < size - 1) {
                    node->next = Q.front();
                }
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }
        return root;
    }
};




// Old Approach
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