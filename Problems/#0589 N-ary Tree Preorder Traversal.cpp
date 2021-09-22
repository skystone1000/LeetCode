// April Challenge 2021 - Day 20
// #0589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Iterative
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> output;
        
        if(root == NULL) return output;
        
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            output.push_back(curr->val);
            reverse(curr->children.begin(),curr->children.end());
            for(Node* child:curr->children){
                st.push(child);
            }
        }
        
        return output;
    }
};

/*
// Recursive
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> trav;
        preOrder(root, trav);
        return trav;
    }
    
    void preOrder(Node* root, vector<int> &trav){
        if(root == NULL) return;
        
        trav.push_back(root->val);
        for(Node* curr : root->children){
            preOrder(curr,trav);
        }
    }
};
*/