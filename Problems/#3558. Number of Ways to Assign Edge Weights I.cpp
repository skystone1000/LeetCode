// #3558. Number of Ways to Assign Edge Weights I
// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/
// Topics - Math, Tree, Depth-First Search

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    const int MOD = 1e9 + 7;

    void dfs(int node, int parent, int depth, vector<vector<int>>& adj, int& maxDepth) {
        maxDepth = max(maxDepth, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj, maxDepth);
            }
        }
    }

    int countOddCostWays(int d) {
        // dp[i][0] = number of ways to reach even sum at i steps
        // dp[i][1] = number of ways to reach odd sum at i steps
        vector<vector<int>> dp(d + 1, vector<int>(2, 0));
        dp[0][0] = 1; // Zero edges, sum is even

        for (int i = 1; i <= d; ++i) {
            // Choosing weight 1: flips parity
            // Choosing weight 2: keeps parity
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD; // Even = even+2 or odd+1
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; // Odd = even+1 or odd+2
        }
        return dp[d][1]; // Total odd-sum ways
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        // Step 1: Build tree (adjacency list)
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Find max depth via DFS
        int maxDepth = 0;
        dfs(1, 0, 0, adj, maxDepth);

        // Step 3: Compute number of odd-sum weight assignments
        return countOddCostWays(maxDepth);
    }
};