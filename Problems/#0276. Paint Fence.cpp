// #0276. Paint Fence
// https://leetcode.com/problems/paint-fence/description/
// Company tag - Google

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Bottom-Up, Constant Space
// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k*k;

        int prev2nd = k;
        int  prev1st= k*k;

        for(int i=3;i<=n;i++){
            int curr = (k-1) * (prev1st + prev2nd);
            prev2nd = prev1st;
            prev1st = curr;
        }
        return prev1st;
    }
};


// Approach 2: Bottom-Up Dynamic Programming (Tabulation)
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    int numWays(int n, int k) {
        unordered_map<int, int> memo;
        memo[1] = k; memo[2] = k*k;

        for(int i=3;i<=n;i++){
            memo[i] = (k-1) * (memo[i-1] + memo[i-2]);
        }
        return memo[n];
    }
};


// Approach 1: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    unordered_map<int, int> memo;

    int totalWays(int i, int k) {
        if (i == 1) return k;
        if (i == 2) return k * k;

        if (memo.count(i)) {
            return memo[i];
        }

        // recurrence: (k - 1) * (ways[i-1] + ways[i-2])
        memo[i] = (k - 1) * (totalWays(i - 1, k) + totalWays(i - 2, k));
        return memo[i];
    }

    int numWays(int n, int k) {
        return totalWays(n, k);
    }
};