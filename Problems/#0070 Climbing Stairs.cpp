// Company Amazon
// 09 #0070 Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        // Method 0 
        // Brute force (TLE)
        // Time - O(2^n)  Space - O(n) recursion stack
        // return climb_Stairs(0, n);
        
        
        
        // Method 1
        // Memoization (Recursive)
        // Time - O(n)  Space - O(n)
        vector<int> memo(n + 1);
        return climb_Stairs1(0, n, memo);
        
        
        
        // Method 2 
        // Dynamic programming Simple
        // Time - O(n)  Space - O(n)
        /*
        vector<int> arr(n+1);
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2;i<=n;i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
        */
        
        
        
        // Method 3 
        // Dp Simple Const Space
        // Time - O(n)  Space - O(1)
        /*
        vector<int> steps(3, 0);
        steps[0] = 1;
        steps[1] = 1;
        for (int i = 2; i <= n; ++i) {
            steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
        }
        return steps[n % 3];
        */
    
    }
    
    int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
    
    int climb_Stairs1(int i, int n, vector<int> &memo) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs1(i + 1, n, memo) + climb_Stairs1(i + 2, n, memo);
        return memo[i];
    }
};