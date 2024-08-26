// #0064. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/
// Company Tag - 41 Amazon, google

#include<bits/stdc++.h>
using namespace std;


// Approach 4: Dynamic Programming (Without Extra Space, In place)
// Time complexity : O(mn), Space complexity : O(1)
// grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1 && j != grid[0].size() - 1)
                    grid[i][j] += grid[i][j + 1];
                else if (j == grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] += grid[i + 1][j];
                else if (j != grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};


// Approach 3: Dynamic Programming 1D
// Time complexity : O(mn), Space complexity : O(mn)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] + dp[j + 1];
                else if (j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[j] = grid[i][j] + dp[j];
                else if (i != grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
                else
                    dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
};


// Approach 2: Dynamic Programming 2D
// Time complexity : O(mn), Space complexity : O(mn)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // If in the last row -> just check right 
                if (i == m - 1 && j != n - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                // If in the last col -> just check down 
                else if (j == n - 1 && i != m - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                // If in the middle -> check right + check down 
                else if (j != n - 1 && i != m - 1)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                // If in the last row, last col -> don't check
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }
};

// Old code
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int arr[grid.size()][grid[0].size()];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i == 0 && j == 0){
                    arr[i][j] = grid[i][j];
                    continue;
                }
                if(i == 0){
                    arr[i][j] = arr[i][j-1] + grid[i][j];
                    continue;
                }
                if(j == 0){
                    arr[i][j] = arr[i-1][j] + grid[i][j];
                    continue;
                }
                arr[i][j] = min(arr[i-1][j]+grid[i][j] , arr[i][j-1]+grid[i][j]);
            }
        }
        
        return arr[grid.size() - 1][grid[0].size() - 1];
    }
};


// Approach 1: Brute Force
// Time complexity : O(2^(m+n)), Space complexity : O(m+n)
class Solution {
public:
    int calculate(vector<vector<int>>& grid, int i, int j) {
        if (i == grid.size() || j == grid[0].size()) return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        return grid[i][j] +
               min(calculate(grid, i + 1, j), calculate(grid, i, j + 1));
    }
    int minPathSum(vector<vector<int>>& grid) { return calculate(grid, 0, 0); }
};