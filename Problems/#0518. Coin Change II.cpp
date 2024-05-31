// #0518. Coin Change II
// https://leetcode.com/problems/coin-change-ii/description/
// Company tag - Google, Amazon, Microsoft

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Dynamic Programming with Space Optimization
// Time complexity: O(n⋅amount) , Space complexity: O(amount).
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1); 
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]]; // This will now use unsigned long long for addition
            }
        }

        return dp[amount] <= INT_MAX ? dp[amount] : -1; 
    }
};


// Approach 2: Bottom-Up Dynamic Programming
// Time complexity: O(n⋅amount) , Space complexity: O(n⋅amount).
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Use long long to handle large values
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1)); 

        // Initialize the base case: There's one way to make amount 0, 
        // which is by not using any coins.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Populate the dp table.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        // Check if the final result exceeds the integer limit and return accordingly.
        // Return -1 if the result exceeds the int limit
        return dp[0][amount] <= INT_MAX ? dp[0][amount] : -1; 
    }
};



// Approach 1: Top-Down Dynamic Programming
// Here n is the size of coins
// Time complexity: O(n⋅amount) , Space complexity: O(n⋅amount).
class Solution {
public:
    vector<int> coins;
    vector<vector<int>> memo;

    int numberOfWays(int i, int amount) {
        if (amount == 0)
            return 1;
        if (i == coins.size() )
            return 0;

        if (memo[i][amount] == -1) {
            if (coins[i] > amount) {
                return memo[i][amount] = numberOfWays(i + 1, amount);
            }
            memo[i][amount] = numberOfWays(i, amount - coins[i]) + numberOfWays(i + 1, amount);
        }

        return memo[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return numberOfWays(0, amount);
    }
};

// Cleaner code
class Solution {
public:
    vector<int> coins;
    vector<vector<int>> memo;

    int numberOfWays(int i, int amount) {
        if (amount == 0)
            return 1;
        if (i == coins.size() || amount < 0)
            return 0;

        if (memo[i][amount] == -1) 
            memo[i][amount] = numberOfWays(i, amount - coins[i]) + numberOfWays(i + 1, amount);

        return memo[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return numberOfWays(0, amount);
    }
};