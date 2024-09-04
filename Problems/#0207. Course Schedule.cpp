// LC - #0207. Course Schedule
// https://leetcode.com/problems/course-schedule/
// TechDose - graph Playlist 09 LC

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Topological Sort Using Kahn's Algorithm
// Here, n be the number of courses and m be the size of prerequisites
// Time complexity: O(m+n), Space complexity: O(m+n)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int nodesVisited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesVisited++;

            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return nodesVisited == numCourses;
    }
};


// Old Approach
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