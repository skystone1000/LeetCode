// #0931. Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/description/
// Company Tag - Amazon, google

#include<bits/stdc++.h>
using namespace std;

// Approach 4: Space Optimized, Bottom-Up Dynamic Programming
// Time Complexity: O(N^2), Space Complexity: O(N)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp(matrix.size() + 1, 0);
        for (int row = matrix.size() - 1; row >= 0; row--) {
            vector<int> currentRow(matrix.size() + 1, 0);
            for (int col = 0; col < matrix.size(); col++) {
                if (col == 0) {
                    currentRow[col] =
                        min(dp[col], dp[col + 1]) + matrix[row][col];
                } else if (col == matrix.size() - 1) {
                    currentRow[col] =
                        min(dp[col], dp[col - 1]) + matrix[row][col];
                } else {
                    currentRow[col] =
                        min(dp[col], min(dp[col + 1], dp[col - 1])) +
                        matrix[row][col];
                }
            }
            dp = currentRow;
        }
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[startCol]);
        }
        return minFallingSum;
    }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
// Time Complexity: O(N^2), Space Complexity: O(N^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                if (col == 0) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1]) + matrix[row][col];
                } else if (col == n - 1) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col - 1]) + matrix[row][col];
                } else {
                    dp[row][col] = min(dp[row + 1][col], min(dp[row + 1][col + 1], dp[row + 1][col - 1])) + matrix[row][col];
                }
            }
        }
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < n; startCol++) {
            minFallingSum = min(minFallingSum, dp[0][startCol]);
        }
        return minFallingSum;
    }
};


// Approach 2: Top Down Dynamic Programming
// Time Complexity: O(N^2), Space Complexity: O(N^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingSum = INT_MAX;
        vector<vector<optional<int>>> memo(
            matrix.size(), vector<optional<int>>(matrix.size(), nullopt));

        // start a DFS (with memoization) from each cell in the top row
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMinFallingPathSum(
                                                   matrix, 0, startCol, memo));
        }
        return minFallingSum;
    }

    int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col,
                              vector<vector<optional<int>>>& memo) {
        // base cases
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        // check if the results are calculated before
        if (memo[row][col] != nullopt) {
            return (memo[row][col]).value_or(0);
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMinFallingPathSum(matrix, row + 1, col - 1, memo);
        int middle = findMinFallingPathSum(matrix, row + 1, col, memo);
        int right = findMinFallingPathSum(matrix, row + 1, col + 1, memo);

        int minSum = min(left, min(middle, right)) + matrix[row][col];

        memo[row][col] = minSum;
        return minSum;
    }
};



// Approach 1: Brute Force Using Depth First Search/ Recursion (TLE)
// Time Complexity: O(N⋅3^N), Space Complexity: O(N)
/*
    Intution
    minimumPath = Minimum(findMinFallingPathSum(row + 1, col + 1),
                          findMinFallingPathSum(row + 1, col),
                          findMinFallingPathSum(row + 1, col - 1))
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMinFallingPathSum(matrix, 0, startCol));
        }
        return minFallingSum;
    }

    int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col) {
        // check if we are out of the left or right boundary of the matrix
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMinFallingPathSum(matrix, row + 1, col);
        int middle = findMinFallingPathSum(matrix, row + 1, col + 1);
        int right = findMinFallingPathSum(matrix, row + 1, col - 1);

        return min(left, min(middle, right)) + matrix[row][col];
    }
};