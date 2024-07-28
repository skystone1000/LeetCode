// #1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 4: Disjoint Set Union (DSU)
// Let n be the number of nodes and m be the number of edges.
// Time complexity: O(m⋅α(n)), Space complexity: O(n)
class UnionFind {
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }   
    void join(int x, int y) {
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                swap(rootX, rootY);
            }
            // Modify the root of the smaller group as the root of the
            // larger group, also increment the size of the larger group.
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);

        for (auto& edge : edges) {
            uf.join(edge[0], edge[1]);
        }
        
        return uf.find(source) == uf.find(destination);
    }
};



// Approach 3: Depth First Search (DFS): Iterative
// Time complexity: O(n+m), Space complexity: O(n+m)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        stack<int> st;
        st.push(start);
        vector<bool> seen(n);
        while (!st.empty()) {
            // Get the current node.
            int node = st.top();
            st.pop();
            
            // Check if we have reached the target node.
            if (node == end)
                return true;
            
            // Check if we've already visited this node.
            if (seen[node]) 
                continue;
            seen[node] = true;
            
            // Add all neighbors to the stack.
            for (int neighbor : adjacency_list[node])
                st.push(neighbor);
        }
        
        return false;
    }
};


// Approach 2: Depth First Search (DFS): Recursive
// Time complexity: O(n+m), Space complexity: O(n+m)
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, vector<bool>& seen, int currNode, int destination) {
        if (currNode == destination) {
            return true;
        }
        seen[currNode] = true;
        for (int nextNode : graph[currNode]) {
            if (!seen[nextNode]) {  // Only call dfs if not seen
                if (dfs(graph, seen, nextNode, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> seen(n, false);
        return dfs(graph, seen, source, destination);
    }
};



// Approach 1: Breadth First Search (BFS)
// Time complexity: O(n+m), Space complexity: O(n+m)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Store all edges in 'graph'.
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // Store all the nodes to be visited in 'bfsQueue'.
        // NOTE: 'queue' conflicts with the type name std::queue, 
        // so we use 'bfsQueue' instead.
        vector<bool> seen(n);
        seen[source] = true;
        queue<int> bfsQueue;
        bfsQueue.push(source);
        
        while (!bfsQueue.empty()) {
            int currNode = bfsQueue.front();
            bfsQueue.pop();
            if (currNode == destination) {
                return true;
            }

            // For all the neighbors of the current node, if we haven't visit it before,
            // add it to 'bfsQueue' and mark it as visited.
            for (auto& nextNode : graph[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    bfsQueue.push(nextNode);
                }
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(start);
        vector<bool> seen(n);
        seen[start] = true;
        
        while (!q.empty()) {
            // Get the current node.
            int node = q.front();
            q.pop();
            
            // Check if we have reached the target node.
            if (node == end) {
                return true;
            }
            
            // Add all neighbors to the stack.
            for (int neighbor : adjacency_list[node]) {
                // Check if neighbor has been added to the queue before.
                if (!seen[neighbor]) {
                    seen[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
    }
};