// #0322. Coin Change
// https://leetcode.com/problems/coin-change/
// Company Tag - 38 Amazon

#include<bits/stdc++.h>
using namespace std;


// Approach 3 (Dynamic programming - Bottom up) [Accepted]
// Time complexity : O(S∗n), Space complexity : O(S)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        vector<int> dp(amount + 1, max);  // Initialize with "infinity"
        /*
		The answer to making change with minimum coins for 0
		will always be 0 coins no matter what the coins we are
		given are
		*/
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) { // Solve every subproblem from 1 to amount
            for (int coin : coins) { // For each coin we are given
                if (coin <= i) { // If it is less than or equal to the sub problem amount
                    dp[i] = min(dp[i], dp[i - coin] + 1);  // See if it gives us a more optimal solution
                }
            }
        }

        /*
		dp[amount] has our answer. If we do not have an answer then dp[amount]
		will be amount + 1 and hence dp[amount] > amount will be true. We then
		return -1.
		Otherwise, dp[amount] holds the answer
		*/

        return dp[amount] > amount ? -1 : dp[amount];
    }
};


// Approach 2 (Dynamic programming - Top down) [Accepted]
// Time complexity : O(S∗n), Space complexity : O(S)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> count(amount, 0);  // Memoization array
        return coinChangeHelper(coins, amount, count);
    }

private:
    int coinChangeHelper(vector<int>& coins, int rem, vector<int>& count) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem - 1] != 0) return count[rem - 1];  // Return memoized result

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = coinChangeHelper(coins, rem - coin, count);
            if (res >= 0 && res < minCoins) {
                minCoins = 1 + res;
            }
        }

        count[rem - 1] = (minCoins == INT_MAX) ? -1 : minCoins;
        return count[rem - 1];
    }
};


// Approach 1 (Brute force) [Time Limit Exceeded]
// S is the amount, n is denomination count
// Time complexity : O(S^n), Space complexity : O(n)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return coinChangeHelper(0, coins, amount);
    }

private:
    int coinChangeHelper(int idxCoin, vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (idxCoin < coins.size() && amount > 0) {
            int maxVal = amount / coins[idxCoin];
            int minCost = INT_MAX;

            for (int x = 0; x <= maxVal; ++x) {
                if (amount >= x * coins[idxCoin]) {
                    int res = coinChangeHelper(idxCoin + 1, coins, amount - x * coins[idxCoin]);
                    if (res != -1)
                        minCost = min(minCost, res + x);
                }
            }

            return (minCost == INT_MAX) ? -1 : minCost;
        }
        return -1;
    }
};