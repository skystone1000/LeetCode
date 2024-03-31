// #0210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 2: Using Node Indegree (Kahn's Algorithm)
// V represents the number of vertices and E represents the number of edges
// Time Complexity: O(V+E), Space Complexity: O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, list<int>> adjList;
        vector<int> indegree(numCourses, 0);
        vector<int> topologicalOrder;

        // Create the adjacency list representation of the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            adjList[src].push_back(dest);

            // Record in-degree of each vertex
            indegree[dest]++;
        }

        // Add all vertices with 0 in-degree to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process until the queue becomes empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topologicalOrder.push_back(node);

            // Reduce the in-degree of each neighbor by 1
            if (adjList.count(node)) {  // This if check not required
                for (auto neighbor : adjList[node]) {
                    indegree[neighbor]--;

                    // If in-degree of a neighbor becomes 0, add it to the queue
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Check to see if topological sort is possible or not
        if (topologicalOrder.size() == numCourses) {
            return topologicalOrder;
        }

        return vector<int>();
    }
};


// Approach 1: Using Depth First Search
// Time Complexity: O(V+E), Space Complexity: O(V+E)
class Solution {
public:
    int WHITE = 1;
    int GRAY = 2;
    int BLACK = 3;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool isPossible = true;
        map<int, int> color;
        map<int, vector<int>> adjList;
        vector<int> topologicalOrder;

        // By default all vertices are WHITE.
        for (int i = 0; i < numCourses; i++) color[i] = WHITE;

        // Create the adjacency list representation of the graph.
        for (vector<int> relation : prerequisites) {
            int dest = relation[0];
            int src = relation[1];
            adjList[src].push_back(dest);
        }

        // If the node is unprocessed, then call dfs on it.
        for (int i = 0; i < numCourses && isPossible; i++) {
            if (color[i] == WHITE) {
                dfs(i, color, adjList, isPossible, topologicalOrder);
            }
        }

        vector<int> order;
        if (isPossible) {
            order.resize(numCourses);
            for (int i = 0; i < numCourses; i++) {
                order[i] = topologicalOrder[numCourses - i - 1];
            }
        }
        return order;
    }

    void dfs(int node, map<int, int>& color, map<int, vector<int>>& adjList,
             bool& isPossible, vector<int>& topologicalOrder) {
        // Don't recurse further if we found a cycle already.
        if (!isPossible) return;

        // Start the recursion.
        color[node] = GRAY;

        // Traverse on neighboring vertices.
        for (int neighbor : adjList[node]) {
            if (color[neighbor] == WHITE) {
                dfs(neighbor, color, adjList, isPossible, topologicalOrder);
            } else if (color[neighbor] == GRAY) {
                // An edge to a GRAY vertex represents a cycle.
                isPossible = false;
            }
        }

        // Recursion ends. We mark it as black.
        color[node] = BLACK;
        topologicalOrder.push_back(node);
    }
};
