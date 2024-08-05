// #3537. Fill a Special Grid
// https://leetcode.com/problems/fill-a-special-grid/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;


// Approach 2: Iterative
// Time complexity: O(2^(2N)), Space complexity: O(2^(2N))
class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        if (N == 0) return {{0}}; 
        vector<vector<int>> prev = specialGrid(N - 1);
        int size = prev.size();
        int newSize = size * 2;
        int area = size * size; 
        vector<vector<int>> result(newSize, vector<int>(newSize)); 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result[i][j + size] = prev[i][j];     
                result[i + size][j + size] = prev[i][j] + area;   
                result[i + size][j] = prev[i][j] + 2 * area;  
                result[i][j] = prev[i][j] + 3 * area;
            }
        }
        
        return result;
    }
};


// Approach 1: Divide and Conquer / Recursive
// Time complexity: O(2^(2N)), Space complexity: O(2^(2N))
class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        vector<vector<int>> grid(size, vector<int>(size));
        solve(grid, 0, size, 0, size);
        return grid;
    }
private:
    int val = 0;
    void solve(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        int size = rowEnd - rowStart;
        if (size == 1){
            grid[rowStart][colStart] = val++;
            return;
        }
        int midRow = rowStart + size / 2;
        int midCol = colStart + size / 2;

        solve(grid, rowStart, midRow, midCol, colEnd); // top right
        solve(grid, midRow, rowEnd, midCol, colEnd); // bottom right
        solve(grid, midRow, rowEnd, colStart, midCol); // bottom left
        solve(grid, rowStart, midRow, colStart, midCol); // top left
    }
};