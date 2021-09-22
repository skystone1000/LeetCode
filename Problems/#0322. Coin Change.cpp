// Company Amazon
// 38 #0322. Coin Change
// https://leetcode.com/problems/coin-change/

// DP Bottom Up Approach
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// This table will store the answer to our sub problems
		vector<int> dp(amount + 1, amount + 1);

		/*
		The answer to making change with minimum coins for 0
		will always be 0 coins no matter what the coins we are
		given are
		*/
		dp[0] = 0;

		// Solve every subproblem from 1 to amount
		for (int i = 1; i <= amount; i++) {
			// For each coin we are given
			for (int j = 0; j < coins.size(); j++) {
				// If it is less than or equal to the sub problem amount
				if (coins[j] <= i) {
					// Try it. See if it gives us a more optimal solution
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
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

// DP Top Down Approach
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 1e5;
                else if (coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        
        return dp[n][amount] > 1e4 ? -1:dp[n][amount];
    }
};