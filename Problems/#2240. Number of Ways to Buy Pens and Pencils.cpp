// #2240. Number of Ways to Buy Pens and Pencils
// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

#include<bits/stdc++.h>
using namespace std;

// Runtime: 17 ms, faster than 100.00% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        // Starting with 0 pens and going till max pens that can be bought in total
        for(int i=0; i * cost1 <= total; i++){
            ways += ((total - i*cost1)/cost2) + 1; // +1 for buying 0 pencils
        }
        return ways;
    }
};