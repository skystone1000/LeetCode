// #0191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 3 - Built-in
    // Runtime: 9 ms, faster than 5.79% of C++ online submissions for Number of 1 Bits.
    // Memory Usage: 5.6 MB, less than 99.97% of C++ online submissions for Number of 1 Bits.
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
    
    // Method 2 - Optimized
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
    // Memory Usage: 6 MB, less than 48.74% of C++ online submissions for Number of 1 Bits.
    /*
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            n = n & n-1;
            ans++;
        }
        return ans;
    }
    */
    
    
    // Method 1 - Brute Force
    /*
    int hammingWeight(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++){
            if(n%2)
                ans++;
            n = n/2;
        }
        return ans;
    }
    */
};