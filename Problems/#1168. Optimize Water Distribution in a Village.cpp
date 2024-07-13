// #1168. Optimize Water Distribution in a Village
// https://leetcode.com/problems/optimize-water-distribution-in-a-village/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Kruskal's Algorithm with Union-Find
// Let N be the number of houses, and M be the number of pipes from the input
// Time Complexity: O((N+M)⋅log(N+M))
// Space Complexity: O(N+M)
class UnionFind {
private:
    vector<int> group;
    vector<int> rank;

public:
    UnionFind(int size) {
        group.resize(size + 1);
        rank.resize(size + 1, 0);
        for (int i = 0; i <= size; ++i) {
            group[i] = i;
        }
    }

    int find(int person) {
        if (group[person] != person) {
            group[person] = find(group[person]);  // Path compression
        }
        return group[person];
    }

    bool unionSet(int person1, int person2) {
        int group1 = find(person1);
        int group2 = find(person2);
        if (group1 == group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2]++;
        }

        return true;
    }
};


class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> edges;

        // Add virtual edges from node 0 to each house with well cost
        for (int i = 0; i < wells.size(); ++i) {
            // [house1j, house2j, costj]
            edges.push_back({0, i + 1, wells[i]});
        }

        // Add all pipe edges
        for (const auto& pipe : pipes) {
            edges.push_back(pipe);
        }

        // Sort all edges by cost
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        UnionFind uf(n);
        int totalCost = 0;

        // Kruskal's algorithm
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            if (uf.unionSet(u, v)) {
                totalCost += cost;
            }
        }

        return totalCost;
    }
};


// Approach 1: Prim's Algorithm with Heap
// Let N be the number of houses, and M be the number of pipes from the input
// Time Complexity: O((N+M)⋅log(N+M)), Space Complexity: O(N+M)
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // Min-heap: pair<cost, house>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Adjacency list: graph[node] = list of {cost, neighbor}
        vector<vector<pair<int, int>>> graph(n + 1);

        // Step 1: Add virtual node 0 to every house with edge = well cost
        for (int i = 0; i < wells.size(); ++i) {
            graph[0].emplace_back(wells[i], i + 1);
            minHeap.emplace(wells[i], i + 1);
        }

        // Step 2: Add bidirectional pipe connections to graph
        for (const auto& pipe : pipes) {
            int house1 = pipe[0], house2 = pipe[1], cost = pipe[2];
            graph[house1].emplace_back(cost, house2);
            graph[house2].emplace_back(cost, house1);
        }

        // Step 3: Prim's algorithm starting from virtual node 0
        unordered_set<int> mstSet;
        mstSet.insert(0);
        int totalCost = 0;

        while (mstSet.size() < n + 1 && !minHeap.empty()) {
            auto [cost, nextHouse] = minHeap.top();
            minHeap.pop();

            if (mstSet.count(nextHouse)) continue;

            mstSet.insert(nextHouse);
            totalCost += cost;

            for (const auto& [edgeCost, neighbor] : graph[nextHouse]) {
                if (!mstSet.count(neighbor)) {
                    minHeap.emplace(edgeCost, neighbor);
                }
            }
        }

        return totalCost;
    }
};
