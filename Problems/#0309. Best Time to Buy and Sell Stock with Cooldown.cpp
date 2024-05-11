// #0309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
// Company Tag - Apple,Amazon,Google,Microsoft

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Dynamic Programming with State Machine
// Time Complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, held = INT_MIN, reset = 0;

        for (int price : prices) {
            int preSold = sold;

            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }

        return max(sold, reset);
    }
};


// Approach 2: Yet-Another Dynamic Programming
// Time Complexity: O(N^2), Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> MP(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            int C1 = 0;
            // Case 1: Buy at i and try selling at j (cooldown after selling)
            for (int sell = i + 1; sell < n; sell++) {
                int profit = (prices[sell] - prices[i]) + MP[sell + 2];
                C1 = max(C1, profit);
            }

            // Case 2: Skip day i
            int C2 = MP[i + 1];

            // Choose max of the two cases
            MP[i] = max(C1, C2);
        }

        return MP[0];
    }
};