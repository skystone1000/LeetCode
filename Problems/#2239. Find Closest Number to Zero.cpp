// #2239. Find Closest Number to Zero
// https://leetcode.com/problems/find-closest-number-to-zero/

#include<bits/stdc++.h>
using namespace std;

// Runtime: 23 ms, faster than 100.00% of C++ online submissions for Find Closest Number to Zero.
// Memory Usage: 19.6 MB, less than 42.86% of C++ online submissions for Find Closest Number to Zero.
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        pair<int,int> largest = {INT_MAX, INT_MAX};
        for(int i=0;i<nums.size();i++){
            int currDist = abs(0 - nums[i]);
            if(largest.second > currDist){
                largest.first = nums[i];
                largest.second = currDist;
            } else if(largest.second == currDist){
                if(largest.first < nums[i]){
                    largest.first = nums[i];
                    largest.second = currDist;
                }
            }
        }
        return largest.first;
    }
};