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