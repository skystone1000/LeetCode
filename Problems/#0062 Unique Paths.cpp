// #0062. Unique Paths
// https://leetcode.com/problems/unique-paths/
// Company Tag - 24 Amazon, Google

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Dynamic Programming - Bottom-up Implementation
// Time complexity: O(N×M), Space complexity: O(N×M)
// Editorial Solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> d(m, vector<int>(n, 1));
        for (int col = 1; col < m; ++col) {
            for (int row = 1; row < n; ++row) {
                d[col][row] = d[col - 1][row] + d[col][row - 1];
            }
        }
        return d[m - 1][n - 1];
    }
};

// Card Solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1; // Base case

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row > 0) {
                    dp[row][col] += dp[row - 1][col];
                }
                if (col > 0) {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};


// Approach 2: Dynamic Programming - Top-down Implementation
// Time complexity: O(N×M), Space complexity: O(N×M)

// Editorial Solution
class Solution {
    vector<vector<int>> memo;

    int dp(int m, int n) {
        if (m == 0 || n == 0) return 1;
        if (memo[m][n] == -1) {
            memo[m][n] = dp(m - 1, n) + dp(m, n - 1);
        }
        return memo[m][n];
    }

public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(m - 1, n - 1);
    }
};


// Card Solution
class Solution {
private:
    vector<vector<int>> memo;

    int dp(int row, int col) {
        if (row + col == 0) {
            return 1; // Base case
        }

        if (memo[row][col] == 0) {
            int ways = 0;
            if (row > 0) {
                ways += dp(row - 1, col);
            }
            if (col > 0) {
                ways += dp(row, col - 1);
            }
            memo[row][col] = ways;
        }

        return memo[row][col];
    }

public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        return dp(m - 1, n - 1);
    }
};


// Approach 3: Math (Python3 only)
// Time complexity: O((M+N)(log(M+N)loglog(M+N))^2) , Space complexity: O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long answer = 1;
        for (int i = n; i < (m + n - 1); ++i) {
            answer *= i;
            answer /= (i - n + 1);
        }
        return static_cast<int>(answer);
    }
};


// Old Solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 1;
        int mat[m][n];
        for(int i=0;i<m;i++){
            mat[i][0] = 1;
        }
        
        for(int i=0;i<n;i++){
            mat[0][i] = 1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j] = mat[i-1][j]+mat[i][j-1];
            }
        }
        
        return mat[m-1][n-1];
    }
};