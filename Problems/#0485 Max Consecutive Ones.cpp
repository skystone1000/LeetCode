// LeetCode arrays 1
// #0485 Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int currOnes = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                currOnes++;
            }else{
                if(maxOnes < currOnes){
                    maxOnes = currOnes;
                }
                currOnes = 0;
            }
        }
        
        // Exit case with 1
        if(currOnes != 0 && maxOnes < currOnes){
            maxOnes = currOnes;
        }
        return maxOnes;
    }
};