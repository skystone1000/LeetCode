// #0310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 2: Topological Sorting
// ∣V∣ be the number of nodes in the graph
// Time Complexity: O(∣V∣), Space Complexity: O(∣V∣)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Edge cases
        if (n < 2) {
            vector<int> centroids;
            for (int i = 0; i < n; ++i)
                centroids.push_back(i);
            return centroids;
        }

        // Build the graph using an adjacency list
        vector<unordered_set<int>> neighbors(n);
        for (const auto& edge : edges) {
            int start = edge[0], end = edge[1];
            neighbors[start].insert(end);
            neighbors[end].insert(start);
        }

        // Initialize the first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (neighbors[i].size() == 1)
                leaves.push_back(i);
        }

        // Trim the leaves until only 1 or 2 centroids remain
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;

            for (int leaf : leaves) {
                int neighbor = *neighbors[leaf].begin(); // the only neighbor
                neighbors[neighbor].erase(leaf);         // remove edge
                if (neighbors[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }

            leaves = newLeaves; // prepare next layer
        }

        // Remaining nodes are the centroids
        return leaves;
    }
};



// Approach 1: Brute Force (BFS from Every Node) - TLE
// Time: O(n^2) (for each node, O(n) traversal), Space: O(n) per BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int minHeight = n;
        vector<int> result;
        for (int root = 0; root < n; ++root) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(root);
            visited[root] = true;
            int height = 0;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                height++;
            }
            if (height < minHeight) {
                minHeight = height;
                result = {root};
            } else if (height == minHeight) {
                result.push_back(root);
            }
        }
        return result;
    }
};