// #0221. Maximal Square
// https://leetcode.com/problems/maximal-square/

#include<bits/stdc++.h>
using namespace std;

// Approach 4: Better Dynamic Programming
// Time complexity : O(mn)
// Space complexity : O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        vector<int> dp(cols + 1, 0);
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
};


// Approach 3: Dynamic Programming
// Time complexity : O(mn), Space complexity : O(mn)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int maxsqlen = 0;
        // for convenience, we add an extra all zero column and row
        // outside of the actual dp table, to simpify the transition
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
};


// Approach 2: Recursion + Memoization
// Time complexity : O(mn), Space complexity : O(mn)
class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<char>> matrix;
    int m,n;
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        this->matrix = matrix;
        memo = vector<vector<int>>(m+1 , vector<int>(n+1, -1));

        int maxSide = 0;
        // Try every cell as the bottom-right of a square
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxSide = max(maxSide, dp(i, j));
            }
        }
        return maxSide * maxSide;
    }

    int dp(int i, int j){
        // Base conditions
        if(i<0 || j<0) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        // Recurrence
        if(matrix[i][j] == '0'){
            memo[i][j] = 0;
        }else if(matrix[i][j] == '1'){
            memo[i][j] = 1 + min(dp(i-1,j), min(dp(i,j-1), dp(i-1,j-1)));
        }
        return memo[i][j];
    }
};


// Approach 1: Brute Force (TLE)
// Time complexity : O(mn)^2, Space complexity : O(1)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    bool flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
};