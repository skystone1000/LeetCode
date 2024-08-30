// #0122 Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Company Tag - 06 Amazon


#include<bits/stdc++.h>
using namespace std;


// Approach 3: Simple One Pass
// Time complexity : O(n), Space complexity : O(1)
/*
    This solution follows the logic used in Approach 2 itself, but with only a slight variation. 
    In this case, instead of looking for every peak following a valley, we can simply go on crawling 
    over the slope and keep on adding the profit obtained from every consecutive transaction. 
    In the end,we will be using the peaks and valleys effectively, but we need not track the costs 
    corresponding to the peaks and valleys along with the maximum profit, but we can directly keep 
    on adding the difference between the consecutive numbers of the array if the second number is 
    larger than the first one, and at the total sum we obtain will be the maximum profit. 
    This approach will simplify the solution.

    This can be made clearer by taking this example:
    [1,​7,​2,​3,​6,​7,​6,​7​]
    The graph corresponding to this array is:
    
    From the above graph, we can observe that the sum A+B+C is equal to the difference D corresponding 
    to the difference between the heights of the consecutive peak and valley.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};


// Approach 2: Peak Valley Approach
// Time complexity : O(n), Space complexity : O(1)
/*
    Say the given array is:
    [7,​1,​5,​3,​6,​4​]
    If we plot the numbers of the given array on a graph, we get:

    If we analyze the graph, we notice that the points of interest are the consecutive valleys and peaks.
    Mathematically speaking:
    Total Profit=∑i​(height(peaki​)−height(valleyi​))

    The key point is we need to consider every peak immediately following a valley to maximize the profit. 
    In case we skip one of the peaks (trying to obtain more profit), we will end up losing the profit over 
    one of the transactions leading to an overall lesser profit.
    For example, in the above case, if we skip peaki​ and valleyj​ trying to obtain more profit by considering 
    points with more difference in heights, the net profit obtained will always be lesser than the one 
    obtained by including them, since C will always be lesser than A+B
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};



// Approach 1: Brute Force
// Time complexity : O(n^n), Space complexity : O(n)
/*
    In this case, we simply calculate the profit corresponding to all the possible 
    sets of transactions and find out the maximum profit out of them.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) { return calculate(prices, 0); }

private:
    int calculate(vector<int>& prices, int s) {
        if (s >= prices.size()) return 0;
        int max = 0;
        for (int start = s; start < prices.size(); start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.size(); i++) {
                if (prices[start] < prices[i]) {
                    int profit =
                        calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit) maxprofit = profit;
                }
            }
            if (maxprofit > max) max = maxprofit;
        }
        return max;
    }
};