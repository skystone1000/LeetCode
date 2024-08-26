// Company Amazon
// 09 #0070 Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

// Approach 4 : Fibonacci (Problem in disguise)
// Use for constant space

// Approach 3: Dynamic Programming
// Time complexity : O(n), Space complexity : O(n)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;

        // Using 1 indexed
        vector<int> dp(n+1);
        dp[1] = 1; dp[2] = 2; 
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


// Approach 2: Recursion with Memoization
// Time complexity : O(n), Space complexity : O(n)
class Solution {
public:
    map<int,int> memo;
    int climbStairs(int n) {
        if(n<=2)
            return n;
        if(memo.find(n) == memo.end())
            memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};
