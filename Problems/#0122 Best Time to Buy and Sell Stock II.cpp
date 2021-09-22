// Company Amazon
// 06 #0122 Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;
        
        int profit = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1] > prices[i]){
                profit += prices[i+1] - prices[i];
            }
        }
        
        return profit;
    }
};