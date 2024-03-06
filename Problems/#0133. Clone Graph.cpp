// #0133. Clone Graph
// https://leetcode.com/problems/clone-graph/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// Approach 1: Depth First Search
// N is a number of nodes (vertices) and M is a number of edges.
// Time Complexity: O(N+M), Space Complexity: O(N)
class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;

        // Check if already visited
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        // Clone Node
        Node* cloneNode = new Node(node->val, {});
        // The key is original node and value being the clone node.
        visited[node] = cloneNode;
        // Iterate neighbors to generate their clones
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

// Approach 2: Breadth First Search
// Time Complexity: O(N+M), Space Complexity: O(N)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        // Hash map to save the visited node,clone => helps (to avoid cycles)
        unordered_map<Node*, Node*> visited;
        deque<Node*> queue{node};
        visited[node] = new Node(node->val, {});
        while (!queue.empty()) {
            Node* n = queue.front();
            queue.pop_front();
            for (Node* neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val, {});
                    queue.push_back(neighbor);
                }
                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};