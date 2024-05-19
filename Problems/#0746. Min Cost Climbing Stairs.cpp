// #0746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/
// Tags - Amazon, Google

#include<bits/stdc++.h>
using namespace std;

// Approach 3: Bottom-Up, Constant Space
// Time Complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0;
        int downTwo = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int temp = downOne;
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            downTwo = temp;
        }

        return downOne;
    }
};


// Approach 2: Bottom-Up Dynamic Programming (Tabulation) (Vector)
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // DP array to store min cost to reach each step
        vector<int> minimumCost(n + 1, 0);

        // Start from step 2 (since 0 and 1 have cost 0)
        for (int i = 2; i <= n; i++) {
            int takeOneStep = minimumCost[i - 1] + cost[i - 1];
            int takeTwoSteps = minimumCost[i - 2] + cost[i - 2];
            minimumCost[i] = min(takeOneStep, takeTwoSteps);
        }

        // Return the min cost to reach the top (step n)
        return minimumCost[n];
    }
};


// Approach 2: Bottom-Up Dynamic Programming (Tabulation) (Hashmap)
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        map<int,int> minValue;
        minValue[0] = 0; minValue[1] = 0;
        for(int i=2;i<=cost.size();i++){
            minValue[i] = min(minValue[i-1] + cost[i-1] , minValue[i-2] + cost[i-2]);
        }
        return minValue[cost.size()];
    }
};


// Approach 1: Recursion with Memoization
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public: 
    map<int,int> minValue;
    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost.size(), cost);
    }

    int solve(int n, vector<int>& cost){
        // Base Case
        if(n <= 1)
            return 0;
        
        if(minValue.find(n) == minValue.end()){
            // Took 1 step = min cost to reach till n-1 + cost at n-1 step
            int oneStep = solve(n-1, cost) + cost[n-1];
            int twoStep = solve(n-2, cost) + cost[n-2];
            minValue[n] = min (oneStep,twoStep);
        }

        return minValue[n];
    }
};