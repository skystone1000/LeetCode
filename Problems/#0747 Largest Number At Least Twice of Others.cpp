// LeetCode Arrays & Strings - 2
// #0747 Largest Number At Least Twice of Others 
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = 0;
        int largest = 0,secondLargest = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
                idx = i;
                continue;
            }

            if(nums[i]>secondLargest){
                secondLargest = nums[i];
                continue;
            }
        }

        if(secondLargest*2 <= largest){
            return idx;
        }else{
            return -1;
        }
    }
};