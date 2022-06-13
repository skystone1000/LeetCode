// LeetCode arrays 3
// #0977 Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;



// Method 2 - Time O(NlogN) 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i] * nums[i];
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};