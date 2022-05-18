// #1192. Critical Connections in a Network
// https://leetcode.com/problems/critical-connections-in-a-network/

// Runtime: 678 ms, faster than 79.42% of C++ online submissions for Critical Connections in a Network.
// Memory Usage: 175.4 MB, less than 72.23% of C++ online submissions for Critical Connections in a Network.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> bridges;
    
    void dfs(int node, int parent, vector<int> &vis, vector<int>&tin, vector<int> &low, int timer, vector<int> adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it: adj[node]){
            if(it==parent) continue;
            
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node])
                    bridges.push_back({node,it});
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        int timer = 0;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,-1,vis,tin,low,timer,adj);
        }
        
        return bridges;
    }
};