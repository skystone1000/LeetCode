// #0121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;


// Aproach 3: Kadane’s Algorithm
// Time complexity: O(n), Space complexity: O(1)
/*
    How is Kadane’s Algorithm Related?
    - Kadane’s Algorithm is used to find the maximum sum subarray in a sequence.
    - In this stock problem, if you look at differences between consecutive days 
    (prices[i+1] - prices[i]), you can reformulate the problem:
        - The maximum profit from one transaction is the largest sum of a 
        contiguous subarray of these differences (with the caveat that the 
        subarray can only start at or after the beginning).

    Transforming the Problem
        1) Compute Price Differences:
            - Let diff[i] = prices[i+1] - prices[i]
            - The goal: Find the subarray (must be contiguous, can be empty) of diff with the maximum sum.
            - This is exactly what Kadane’s Algorithm does!

        2) Why does this work?
            - Buying on day i and selling on day j (where j>i) gives profit prices[j] - prices[i]
            - That profit is the sum of all prices[k+1] - prices[k] for k from i to j-1
            - So finding the max profit is finding the max subarray sum of the diff array.

    This is mathematically equivalent to the classic one-pass approach, but uses Kadane’s insight.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int max_curr = 0, max_so_far = 0;
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            max_curr = max(diff, max_curr + diff);
            max_so_far = max(max_so_far, max_curr);
        }
        return max_so_far;
    }

};

// Approach 2: One Pass
// Time complexity: O(n), Space complexity: O(1)
// Cleaner code
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

// Easy to understand
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};



// Approach 1: Brute Force (TLE)
// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit) maxprofit = profit;

                // maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxprofit;
    }
};