// #0163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0)
            return {{lower,upper}};

        vector<vector<int>> missingRanges;
        if(nums[0]>lower){
            missingRanges.push_back({lower,nums[0]-1});
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1 != nums[i+1]){
                missingRanges.push_back({nums[i]+1,nums[i+1]-1});
            }
        }
        if(nums[nums.size()-1] < upper){
            missingRanges.push_back({nums[nums.size()-1]+1,upper});
        }
        return missingRanges;
    }
};