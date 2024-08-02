// #3532. Path Existence Queries in a Graph I
// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Single Pass
// Time complexity: O(N + Q), Space Complexity: O(N)
/*
    Intuition
    Since nums array is already sorted,
    if two nodes are connected directly or indirectly,
    their numbers will differ by at most maxDiff at every step.
    So we can group connected nodes together while traversing once.
*/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);
        int currentGroup = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentGroup++;
            }
            group[i] = currentGroup;
        }

        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            res.push_back(group[u] == group[v]);
        }
        return res;
    }
};



// Approach 0: Disjoint Set (TLE)
// Time complexity: O(((N^2)+Q)), Space complexity: O(n)
class UnionFind {
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }   
    void join(int x, int y) {
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                swap(rootX, rootY);
            }
            // Modify the root of the smaller group as the root of the
            // larger group, also increment the size of the larger group.
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(nums[i]-nums[j]) <= maxDiff){
                    uf.join(i,j);
                }
            }
        }

        vector<bool> ans;
        for(auto query:queries){
            ans.push_back(uf.isConnected(query[0],query[1]));
        }
        return ans;

    }
};


// Approach 0: Brute force  (TLE)
// Time complexity: O((N^2) + (Q.N^2)), Space complexity - O(N^2)
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(nums[i]-nums[j]) <= maxDiff){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> ans;
        for(auto query:queries){
            vector<int> seen(n,0);
            ans.push_back(checkPath(query[0],query[1],seen,graph));
        }
        return ans;
    }

    bool checkPath(int src, int dest, vector<int>& seen, vector<vector<int>>& graph){
        if(src == dest) return true;

        seen[src] = 1;
        for(auto node:graph[src]){
            if(seen[node] == 0){
                if(checkPath(node, dest, seen, graph))
                    return true;
            }
        }
        return false;
    }
};