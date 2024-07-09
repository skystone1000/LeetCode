// #1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/description/
// Tags - Amazon, Google

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Better Dynamic Programming (Bottom Up)
// Time Complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            return n > 0 ? 1 : 0;
        }
        
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < n - 2; ++i) {
            int tmp = a + b + c;
            a = b; b = c; c = tmp;
        }
        
        return c;
    }
};

// Approach 1: Dynamic Programming (Bottom Up)(Map)
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    int tribonacci(int n) {
        map<int,int> memo;
        memo[0] = 0; memo[1] = 1; memo[2] = 1;
        for(int i=3;i<=n;i++){
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        }
        return memo[n];
    }
};


// Approach 2: Dynamic Programming (Top Down)
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    map<int,int> memo;
    int tribonacci(int n){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        if(memo.find(n) == memo.end()){
            memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
        return memo[n];
    }
};
