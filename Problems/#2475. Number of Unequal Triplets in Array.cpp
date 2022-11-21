// #2475. Number of Unequal Triplets in Array
// https://leetcode.com/problems/number-of-unequal-triplets-in-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                for(int k=j+1;k<nums.size();k++)
                    if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                        count++;
       
        return count;
    }
};