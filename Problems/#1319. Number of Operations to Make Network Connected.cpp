// #1319. Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - DFS
// Runtime: 182 ms, faster than 49.30% of C++ online submissions for Number of Operations to Make Network Connected.
// Memory Usage: 59.8 MB, less than 13.43% of C++ online submissions for Number of Operations to Make Network Connected.
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;
        
        // Step 1 - Make Adjacency List
        int edges = 0;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges += 1;
        }
        
        // Step 2 - Find Number of Components
        int components = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                components += 1;
                DFS(adj, i, visited);
            }
        }
        
        // Step 3 - Count Number of Edges
        if(edges < n-1) // No of edges less than that in MST
            return -1;
        
        int redundant = edges - ( (n-1) - (components-1) ); // Count redundant edges
        if(redundant >= (components-1)) // Check if we can join components using redundant edges
            return components-1;
        return -1;
    }
    
    void DFS(unordered_map<int, vector<int>> &adj, int curr, vector<bool> &visited){
        visited[curr] = true;
        
        for(auto i:adj[curr])
            if(visited[i] == false)
                DFS(adj, i, visited);
    }
};

// Method 2 - Union Find
// Runtime: 118 ms, faster than 92.29% of C++ online submissions for Number of Operations to Make Network Connected.
// Memory Usage: 37.2 MB, less than 99.40% of C++ online submissions for Number of Operations to Make Network Connected.
class Solution {
public:
    vector<int> parent;
    int find(int node){
        if(node ==parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c = connections.size();
        if (n-1 > c) 
            return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < c; i++) {
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if (x != y) 
                parent[y] = x;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
            if(parent[i] == i)
                ans++;
        
        return ans-1;
    }
};