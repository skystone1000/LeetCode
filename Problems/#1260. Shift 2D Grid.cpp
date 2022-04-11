// #1260. Shift 2D Grid
// https://leetcode.com/problems/shift-2d-grid/

// Runtime: 33 ms, faster than 69.23% of C++ online submissions for Shift 2D Grid.
// Memory Usage: 15 MB, less than 19.94% of C++ online submissions for Shift 2D Grid.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        
        int idx = arr.size()- (k % arr.size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                grid[i][j] = arr[idx % arr.size()];
                idx++;
            }
        }
        return grid;
    }
};
