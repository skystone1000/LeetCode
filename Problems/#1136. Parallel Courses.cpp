// #1136. Parallel Courses
// https://leetcode.com/problems/parallel-courses/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 3: Depth-First Search: Combine
// Time Complexity: O(N+E), Space Complexity: O(N+E)
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
        }

        vector<int> visited(N + 1, 0);
        int maxLength = 1;
        for (int node = 1; node < N + 1; node++) {
            int length = dfs(node, graph, visited);
            // we meet a cycle!
            if (length == -1) {
                return -1;
            }
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }

private:
    int dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        // return the longest path (inclusive)
        if (visited[node] != 0) {
            return visited[node];
        } else {
            // mark as visiting
            visited[node] = -1;
        }
        int maxLength = 1;
        for (auto& endNode : graph[node]) {
            int length = dfs(endNode, graph, visited);
            // we meet a cycle!
            if (length == -1) {
                return -1;
            }
            maxLength = max(length + 1, maxLength);
        }
        // mark as visited
        visited[node] = maxLength;
        return maxLength;
    }
};



// Approach 2: Depth-First Search: Check for Cycles + Find Longest Path
// Time Complexity: O(N+E), Space Complexity: O(N+E)
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
        }
        // check if the graph contains a cycle
        vector<int> visited(N + 1, 0);
        for (int node = 1; node < N + 1; node++) {
            // if has cycle, return -1
            if (dfsCheckCycle(node, graph, visited) == -1) {
                return -1;
            }
        }

        // if no cycle, return the longest path
        vector<int> visitedLength(N + 1, 0);
        int maxLength = 1;
        for (int node = 1; node < N + 1; node++) {
            int length = dfsMaxPath(node, graph, visitedLength);
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }

private:
    int dfsCheckCycle(int node, vector<vector<int>>& graph, vector<int>& visited) {
        // return -1 if has a cycle
        // return 1 if does not have any cycle
        if (visited[node] != 0) {
            return visited[node];
        } else {
            // mark as visiting
            visited[node] = -1;
        }
        for (auto& endNode : graph[node]) {
            if (dfsCheckCycle(endNode, graph, visited) == -1) {
                // we meet a cycle!
                return -1;
            }
        }
        // mark as visited
        visited[node] = 1;
        return 1;
    }

    int dfsMaxPath(int node, vector<vector<int>>& graph, vector<int>& visitedLength) {
        // return the longest path (inclusive)
        if (visitedLength[node] != 0) {
            return visitedLength[node];
        }
        int maxLength = 1;
        for (auto& endNode : graph[node]) {
            int length = dfsMaxPath(endNode, graph, visitedLength);
            maxLength = max(length + 1, maxLength);
        }
        // store it
        visitedLength[node] = maxLength;
        return maxLength;
    }
};




// Approach 1: Breadth-First Search (Kahn's Algorithm)
// Time Complexity: O(N+E), Space Complexity: O(N+E)
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> indegree(N + 1, 0);  // or indegree
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        int step = 0;
        int studiedCount = 0;
        vector<int> bfsQueue;
        for (int node = 1; node < N + 1; node++) {
            if (indegree[node] == 0) {
                bfsQueue.push_back(node);
            }
        }
        // start learning with BFS
        while (!bfsQueue.empty()) {
            // start new semester
            step++;
            vector<int> nextQueue;
            for (auto& node : bfsQueue) {
                studiedCount++;
                for (auto& endNode : graph[node]) {
                    indegree[endNode]--;
                    // if all prerequisite courses learned
                    if (indegree[endNode] == 0) {
                        nextQueue.push_back(endNode);
                    }
                }
            }
            bfsQueue = nextQueue;
        }

        // check if learn all courses
        return studiedCount == N ? step : -1;
    }
};
