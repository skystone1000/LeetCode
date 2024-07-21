// #1770. Maximum Score from Performing Multiplication Operations
// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/
// Tags - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 4: Space-Optimized Dynamic Programming
// Time complexity: O(M^2), Space complexity: O(M)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // For Right Pointer
        int n = int(nums.size());
        // Number of Operations
        int m = int(multipliers.size());
        vector<int> dp(m + 1, 0);
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = 0; left <= op; left++) {
                dp[left] = max(multipliers[op] * nums[left] + dp[left + 1],
                               multipliers[op] * nums[n - 1 - (op - left)] + dp[left]);
            }
        }
        
        return dp[0];
    }
};



// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
// Time complexity: O(M^2), Space complexity: O(M^2)
class Solution{
    public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> memo = vector<vector<int>>(m+1, vector<int>(m+1, 0));

        for(int i=m-1 ; i>=0 ; i--){
            for(int left = i ; left >= 0 ; left--) {
                int mult = multipliers[i];
                int right = n-1 - (i-left);
                memo[i][left] =  max(mult*nums[left] + memo[i+1][left+1],
                        mult*nums[right] + memo[i+1][left]); 
            }
        }
        
        return memo[0][0];
    }
};


// Approach 2: Top-Down Dynamic Programming (Recusion + Memoization)
// Time complexity: O(M^2), Space complexity: O(M^2)
class Solution {
private:
    vector<vector<int>> memo;
    vector<int> nums, multipliers;
    int n, m;

    int dp(int i, int left) {
        // Base case
        if (i == m) return 0;  

        int right = n - 1 - (i - left);
        int mult = multipliers[i];

        if (memo[i][left] == INT_MIN) {
            int pickLeft = mult * nums[left] + dp(i + 1, left + 1);
            int pickRight = mult * nums[right] + dp(i + 1, left);
            memo[i][left] = max(pickLeft, pickRight);
        }

        return memo[i][left];
    }

public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this->nums = nums;
        this->multipliers = multipliers;
        n = nums.size();
        m = multipliers.size();

        // Initialize memo with INT_MIN to indicate uncomputed states
        memo = vector<vector<int>>(m, vector<int>(m, INT_MIN));

        return dp(0, 0);
    }
};


// Approach 1: Brute Force (TLE)
// Time complexity: O(2^M), Space complexity: O(M)
class Solution {
    public:
    // op -> current operation
    int helper(vector<int>& nums, vector<int>& multipliers, int left, int right, int op) { 
        if (op == int(multipliers.size())) {
            return 0;
        }
        
        int l = nums[left] * multipliers[op] + helper(nums, multipliers, left + 1, right, op + 1);
        int r = nums[right] * multipliers[op] + helper(nums, multipliers, left, right - 1, op + 1);
        
        return max(l, r);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return helper(nums, multipliers, 0, int(nums.size()) - 1, 0);
    }
};