// #1101. The Earliest Moment When Everyone Become Friends
// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/

#include<bits/stdc++.h>
using namespace std;

// Approach: Union-Find (Disjoint-Set)
// Let N be the number of people and M be the number of logs.
// Time Complexity: O(N+MlogM+Mα(N))
// Space Complexity: O(N+M) or O(N+logM)

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int person) {
        if (parent[person] != person) {
            parent[person] = find(parent[person]); // Path compression
        }
        return parent[person];
    }

    bool unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;

        // Union by rank
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }

        return true; 
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        if (logs.size() < n - 1) return -1; 

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        UnionFind uf(n);
        int groupCount = n;

        for (const auto& log : logs) {
            int timestamp = log[0];
            int friendA = log[1];
            int friendB = log[2];

            if (uf.unionSet(friendA, friendB)) {
                groupCount--;
            }

            if (groupCount == 1) {
                return timestamp;
            }
        }

        return -1;
    }
};



/*
    Approach 1: Brute-force Graph Construction + BFS/DFS
    Algorithm / DS Used
        For each timestamp, build the friendship graph and check connectivity via BFS/DFS.

    Idea
        Inefficient: reconstruct graph for each timestamp and run BFS/DFS to see if all nodes are reachable from any node.

    Complexity
        Time: O(T * (N + E)), with T = number of logs
        Space: O(N + E)
        Not scalable for large input.
*/