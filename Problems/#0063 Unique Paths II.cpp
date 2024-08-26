// April Challenge 2021 - Day 28
// #0063. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

#include<bits/stdc++.h>
using namespace std;

// Method 3 - DP iterative
// Time Complexity : O(M*N), Space Complexity : O(M*N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            if(grid[i][0])  break;
            dp[i][0] = 1;
        }
        
        for(int i=0;i<col;i++){
            if(grid[0][i])  break;
            dp[0][i] = 1;
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                // Obstacle
                if(grid[i][j])  continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[row-1][col-1];
    }
};

// Editorial code
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();
        // If the starting cell has an obstacle, then simply return as there
        // would be no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;
        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] =
                (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }
        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] =
                (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }
        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] =
                        obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        // Return value stored in rightmost bottommost cell. That is the
        // destination.
        return obstacleGrid[R - 1][C - 1];
    }
};


// Method 2 - Recursive memoization
// Time Complexity : O(M*N), Space Complexity : O(M*N)
class Solution {
public:
    int m, n;
    vector<vector<int> > dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        dp.resize(m, vector<int>(n));
        return solve(obstacleGrid, 0, 0);
    }
    
    int solve(vector<vector<int>>& grid, int i, int j) {
        // bounds checking
        if(i < 0 || j < 0 || i >= m || j >= n) 
            return 0;
        
        // obstacle found at current cell
        if(grid[i][j]) 
            return dp[i][j] = 0;                 
       
        // reached bottom-right of grid ? return 1
        if(i == m - 1 && j == n - 1) 
            return 1;     
        
        // if already computed for current cell
        if(dp[i][j]) 
            return dp[i][j];                      
        
        // recursively explore the two options available with us
        return dp[i][j] = solve(grid, i + 1, j) + solve(grid, i, j + 1); 
    }
};




// Method 1 - Brute force - Recursive Approach (TLE)
class Solution {
public:
    int m, n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {        
        m = obstacleGrid.size(), n = obstacleGrid[0].size();  
        return solve(obstacleGrid, 0, 0);   
    }
    // function to recursively explore all unique paths
    int solve(vector<vector<int> >& grid, int i, int j){
        // bounds checking
        if(i < 0 || j < 0 || i >= m || j >= n) 
            return 0;          

        // if there's obstacle, just return 0 and stop further exploration
        if(grid[i][j]) 
            return 0;   

        // if we have reached end cell, return 1 if there's no obstacle
        if(i == m - 1 && j == n - 1 && !grid[i][j]) 
            return 1;        

        // explore the two choice we have at each cell
        return solve(grid, i + 1, j) + solve(grid, i, j + 1);     
    }
};