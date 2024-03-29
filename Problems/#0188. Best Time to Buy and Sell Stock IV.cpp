// #0188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
// Company Tag - Apple,Amazon,Meta,Google,Microsoft

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Merging
// Time Complexity: O(n(n−k)), Space Complexity: O(n)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        // find all consecutively increasing subsequence
        vector<vector<int>> transactions;
        int start = 0;
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                end = i;
            } else {
                if (end > start) {
                    vector<int> t = {start, end};
                    transactions.push_back(t);
                }
                start = i;
            }
        }
        if (end > start) {
            vector<int> t = {start, end};
            transactions.push_back(t);
        }

        while (transactions.size() > k) {
            // check delete loss
            int delete_index = 0;
            int min_delete_loss = INT_MAX;
            for (int i = 0; i < transactions.size(); i++) {
                vector<int> t = transactions[i];
                int profit_loss = prices[t[1]] - prices[t[0]];
                if (profit_loss < min_delete_loss) {
                    min_delete_loss = profit_loss;
                    delete_index = i;
                }
            }

            // check merge loss
            int merge_index = 0;
            int min_merge_loss = INT_MAX;
            for (int i = 1; i < transactions.size(); i++) {
                vector<int> t1 = transactions[i - 1];
                vector<int> t2 = transactions[i];
                int profit_loss = prices[t1[1]] - prices[t2[0]];
                if (profit_loss < min_merge_loss) {
                    min_merge_loss = profit_loss;
                    merge_index = i;
                }
            }

            // delete or merge
            if (min_delete_loss <= min_merge_loss) {
                transactions.erase(transactions.begin() + delete_index);
            } else {
                vector<int>& t1 = transactions[merge_index - 1];
                vector<int>& t2 = transactions[merge_index];
                t1[1] = t2[1];
                transactions.erase(transactions.begin() + merge_index);
            }
        }

        int res = 0;
        for (auto& t : transactions) {
            res += prices[t[1]] - prices[t[0]];
        }

        return res;
    }
};


// Approach 1: Dynamic Programming
// Time Complexity: O(nk), Space Complexity: O(nk)
/*
    Intution
    1) Keep holding the stock:
        dp[i][j][1]=dp[i−1][j][1]
    2) Keep not holding the stock:
        dp[i][j][0]=dp[i−1][j][0]
    3) Buying, when j>0:
        dp[i][j][1]=dp[i−1][j−1][0]−prices[i]
    4) Selling:
        dp[i][j][0]=dp[i−1][j][1]+prices[i]

    Recurrence relation (1+2+3+4)
    dp[i][j][1]=max(dp[i−1][j][1],dp[i−1][j−1][0]−prices[i])
    dp[i][j][0]=max(dp[i−1][j][0],dp[i−1][j][1]+prices[i])
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // Solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        if (k * 2 >= n) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        // dp[i][used_k][is_hold] = balance
        // is_hold: 0 not_hold, 1 hold
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        // initialize the array with -inf
        // we use INT_MIN/2 here to prevent overflow
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = INT_MIN / 2;
                dp[i][j][1] = INT_MIN / 2;
            }
        }

        // set starting value
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        // fill the array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // transition equation
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // you can't hold stock without any transaction
                if (j > 0) {
                    dp[i][j][1] =
                        max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = max(res, dp[n - 1][j][0]);
        }

        return res;
    }
};