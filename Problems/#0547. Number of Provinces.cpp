// #0547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Depth First Search
// Here n is the number of cities.
// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        int n = isConnected.size();
        
        vector<bool> visited(n, false);
        int provinces = 0;
        for(int i=0;i< visited.size();i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
    
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited){
        visited[i] = true;
        for(int j=0;j<visited.size();j++){
            if(i!=j && isConnected[i][j] && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }
};

// Approach 2: Breadth First Search
// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] && !visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                bfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};

// Approach 3: Union-find
// Time complexity: O(n^2), Space complexity: O(n)
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};

// Method 2 - Union Find (OLD)
// Runtime: 45 ms, faster than 23.29% of C++ online submissions for Number of Provinces.
// Memory Usage: 13.6 MB, less than 87.84% of C++ online submissions for Number of Provinces.
class Solution {
public:
    int parent[1000];
    
    int findPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i=0;i<1000;i++)
            parent[i] = i;
        
        int provinces = isConnected.size();
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1){
                    int x = findPar(i);
                    int y = findPar(j);
                    if(x != y){
                        parent[x] = y;
                        provinces--;
                    }
                }
            }
        }
        return provinces;
        
    }
};