// #0323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 2: Disjoint Set Union (DSU)
// E = Number of edges, V = Number of vertices
// Time complexity: O(V+E⋅α(n)), Space complexity: O(V)
class Solution {
public:
    int find(vector<int> &representative, int vertex) {
        if (vertex == representative[vertex]) {
            return vertex;
        }
        return representative[vertex] = find(representative, representative[vertex]);
    }
    
    int combine(vector<int> &representative, vector<int> &size, int vertex1, int vertex2) {
        vertex1 = find(representative, vertex1);
        vertex2 = find(representative, vertex2);
        if (vertex1 == vertex2) {
            return 0;
        } else {
            if (size[vertex1] > size[vertex2]) {
                size[vertex1] += size[vertex2];
                representative[vertex2] = vertex1;
            } else {
                size[vertex2] += size[vertex1];
                representative[vertex1] = vertex2;
            }
            return 1;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> representative(n), size(n);
        for (int i = 0; i < n; i++) {
            representative[i] = i;
            size[i] = 1;
        }
        
        int components = n;
        for (int i = 0; i < edges.size(); i++) {
            components -= combine(representative, size, edges[i][0], edges[i][1]);
        }

        return components;
    }
};


// Approach 1: Depth-First Search (DFS)
// Time complexity: O(E+V), Space complexity: O(E+V)

class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &visited, int src) {
        visited[src] = 1;
        
        for (int i = 0; i < adjList[src].size(); i++) {
            if (visited[adjList[src][i]] == 0) {
                dfs(adjList, visited, adjList[src][i]);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
      
        int components = 0;
        vector<int> visited(n, 0);
        vector<int> adjList[n];
    
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                dfs(adjList, visited, i);
            }
        }
        return components;
    }
};