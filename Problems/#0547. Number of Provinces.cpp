// #0547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - DFS
// Runtime: 48 ms, faster than 19.53% of C++ online submissions for Number of Provinces.
// Memory Usage: 13.7 MB, less than 62.95% of C++ online submissions for Number of Provinces.
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


// Method 2 - Union Find
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