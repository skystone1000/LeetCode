// #1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/
// Tags - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 4: Dynamic Programming with Space Optimization - two 1D arrays (previous and current)
// Time complexity : O(M⋅N), Space complexity : O(min(M,N))
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Ensure text1 is the shorter string
        if (text2.length() < text1.length()) {
            swap(text1, text2);
        }

        int n = text1.length();
        int m = text2.length();

        // Create two 1D DP arrays for previous and current
        vector<int> previous(n + 1, 0);
        vector<int> current(n + 1, 0);

        // Traverse text2 from right to left
        for (int col = m - 1; col >= 0; col--) {
            for (int row = n - 1; row >= 0; row--) {
                if (text1[row] == text2[col]) {
                    current[row] = 1 + previous[row + 1];
                } else {
                    current[row] = max(previous[row], current[row + 1]);
                }
            }
            // Swap current and previous for the next iteration
            swap(current, previous);
        }

        // Final answer is in previous[0]
        return previous[0];
    }
};


// Approach 3: Dynamic Programming
// Time complexity : O(M⋅N), Space complexity : O(M⋅N)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Create a 2D DP grid initialized to 0
        vector<vector<int>> dpGrid(n + 1, vector<int>(m + 1, 0));

        // Fill the grid from bottom-right to top-left
        for (int col = m - 1; col >= 0; col--) {
            for (int row = n - 1; row >= 0; row--) {
                if (text1[row] == text2[col]) {
                    dpGrid[row][col] = 1 + dpGrid[row + 1][col + 1];
                } else {
                    dpGrid[row][col] = max(dpGrid[row + 1][col], dpGrid[row][col + 1]);
                }
            }
        }

        // Return the result at the top-left corner
        return dpGrid[0][0];
    }
};


// Approach 2: Improved Memoization
// Time complexity : O(M⋅N), Space complexity : O(M⋅N)
class Solution {
private:
    vector<vector<int>> memo;
    string text1, text2;

    int memoSolve(int p1, int p2) {
        // Base case or already computed
        if (memo[p1][p2] != -1)
            return memo[p1][p2];

        int answer = 0;
        if (text1[p1] == text2[p2]) {
            answer = 1 + memoSolve(p1 + 1, p2 + 1);
        } else {
            answer = max(memoSolve(p1, p2 + 1), memoSolve(p1 + 1, p2));
        }

        return memo[p1][p2] = answer;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;

        int n = text1.size();
        int m = text2.size();

        // Initialize memo with -1
        memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        // Base cases: if pointer reaches end of string, result is 0
        for (int i = 0; i <= n; ++i)
            memo[i][m] = 0;
        for (int j = 0; j <= m; ++j)
            memo[n][j] = 0;

        return memoSolve(0, 0);
    }
};


// Approach 1: Memoization (finding the first matching character)
// Time complexity : O(M⋅N^2), Space complexity : O(M⋅N)
class Solution {
private:
    vector<vector<int>> memo;
    string text1, text2;

    int memoSolve(int p1, int p2) {
        // Base case
        if (p1 >= text1.size() || p2 >= text2.size())
            return 0;

        if (memo[p1][p2] != -1)
            return memo[p1][p2];

        // Option 1: Skip text1[p1]
        int option1 = memoSolve(p1 + 1, p2);

        // Option 2: Try to include text1[p1] if it's found in text2 at or after p2
        int firstOccurrence = text2.find(text1[p1], p2);  // Equivalent to Java's indexOf
        int option2 = 0;
        if (firstOccurrence != string::npos) {
            option2 = 1 + memoSolve(p1 + 1, firstOccurrence + 1);
        }

        return memo[p1][p2] = max(option1, option2);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        int n = text1.size();
        int m = text2.size();

        memo = vector<vector<int>>(n, vector<int>(m, -1));
        return memoSolve(0, 0);
    }
};