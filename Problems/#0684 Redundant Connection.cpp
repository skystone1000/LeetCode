// June Challenge 2021 - Day 25 - #0684. Redundant Connection
// #0684. Redundant Connection
// https://leetcode.com/problems/redundant-connection/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    
    int find(int node){
        while(parent[node] != node)
            node = parent[node];
        
        return node;
    }
    
    void union1(int i, int j){
        int iRoot = find(i);
        int jRoot = find(j);
        
        if(iRoot != jRoot){
            parent[jRoot] = iRoot;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Make each node the parent of itself
        for(int i=0;i<=n;i++)
            parent.push_back(i);
        
        // Loop on all the edges{
        for(vector<int> edge:edges){
            if (find(edge[0]) == find(edge[1]))
                return edge;
            union1(edge[0], edge[1]);
        }
        
        return {};
    }
    
};

// Method 2
// Runtime: 6 ms, faster than 86.53% of C++ online submissions for Redundant Connection.
// Memory Usage: 8.9 MB, less than 73.06% of C++ online submissions for Redundant Connection.
class Solution {
public:
    int parent[10000];
    
    int findPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2,-1);
        
        for(int i=0;i<1000;i++)
            parent[i] = i;
        
        for(int i=0;i<edges.size();i++){
            int x = findPar(edges[i][0]);
            int y = findPar(edges[i][1]);
            if(x != y){
                parent[x] = y;
            }else{
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            }
        }
        return res;
    }
};