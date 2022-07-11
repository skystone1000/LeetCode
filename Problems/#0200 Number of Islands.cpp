// Company Amazon
// 03 #0200 Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include<bits/stdc++.h>
using namespace std;

/*
For all 3 approaches
Time Complexity : O(n x m)
Space Complexity: O(n x m)
Ref: https://leetcode.com/problems/number-of-islands/discuss/1511737/C%2B%2B-All-3-methods-DFS-or-BFS-or-Union-Find
*/

// Method 1: DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){ return 0; }
        
        int numIslands=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j] == '1')
                    numIslands += dfs(grid,i,j);
        
        return numIslands;        
    }
    
    int dfs(vector<vector<char>> &grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j] == '0'){
            return 0;
        }
        grid[i][j] = '0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        
        return 1;
    }
};

// Method 2: BFS
class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j]='0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ci=DR[k]+i;
                int cj=DC[k]+j;
                if(ci<0 || cj<0 || ci>=grid.size() || cj>=grid[0].size())
                    continue;
                if(grid[ci][cj]=='1') {
                    q.push({ci, cj});
                    grid[ci][cj]='0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    no_of_islands++;
                    bfs(i, j, grid);
                }
            }
        }
        return no_of_islands;
    }
};