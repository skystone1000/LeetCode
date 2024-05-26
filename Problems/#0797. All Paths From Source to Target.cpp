// #0797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 1: DFS / Backtracking
// Time Complexity: O(N.2^N), Space Complexity: O(N), graph with N nodes
class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> paths;
public:
    // DFS
    void dfs(int node, vector<int>& path) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.emplace_back(path);
            return;
        }
        vector<int> nextNodes = graph[node];
        for (int nextNode : nextNodes) {
            dfs(nextNode, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.size() == 0) {
            return paths;
        }

        this->graph = graph;
        vector<int> path;
        dfs(0, path);
        return paths;
    }
};



// Approach 2: Top-Down Dynamic Programming(Less Optimized)
// Time Complexity: O(N.2^N), Space Complexity: O(N.2^N), graph with N nodes
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& inputGraph) {
        graph = inputGraph;
        memo.clear();
        return dfs(0);
    }

private:
    vector<vector<int>> graph;
    unordered_map<int, vector<vector<int>>> memo;

    vector<vector<int>> dfs(int node) {
        // If already computed, return cached result
        if (memo.find(node) != memo.end()) {
            return memo[node];
        }

        // If reached target node
        if (node == graph.size() - 1) {
            return {{node}};
        }

        vector<vector<int>> allPaths;
        for (int neighbor : graph[node]) {
            vector<vector<int>> subPaths = dfs(neighbor);
            for (auto path : subPaths) {
                path.insert(path.begin(), node); // Prepend current node
                allPaths.push_back(path);
            }
        }

        memo[node] = allPaths; // Cache result
        return allPaths;
    }
};