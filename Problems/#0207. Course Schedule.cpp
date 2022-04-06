// LC - #0207. Course Schedule
// https://leetcode.com/problems/course-schedule/
// TechDose - graph Playlist 09 LC

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Techdose Cycle check
    bool checkCycle(int curr, vector<int> adj[], vector<int>& vis){
        if(vis[curr] == 2)
            return true;
        
        vis[curr] = 2;
        for(int i=0;i< adj[curr].size();i++){
            // Skipping Already processed Nodes
            if(vis[adj[curr][i]] != 1)
                if(checkCycle(adj[curr][i], adj, vis))
                    return true;
        }
        
        vis[curr] = 1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses+1];
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> vis(numCourses, 0);
        // vector<int> dfsVis(numCourses, 0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
                if(checkCycle(i, adj, vis))
                    return false; // As Cycle is detected
        }
        return true;
    }
    
    // Giving TLE - Striver
    bool checkCycleTLE(int node, vector<int> adj[], vector<int> vis, vector<int> dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(checkCycleTLE(it, adj, vis, dfsVis))
                    return true;
            } else if(dfsVis[it])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }
};