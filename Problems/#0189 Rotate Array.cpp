// LeetCode Arrays & Strings - 16
// #0189 Rotate Array
// https://leetcode.com/problems/rotate-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Extra space
    void rotate(vector<int>& nums, int k) {
        if(nums.size() > 1 && k != 0){ 
            vector<int> ans;
            if(k>nums.size())
                k = k % nums.size(); 
            int counter = nums.size() - k;
            for(int i=0;i<nums.size();i++){
                ans.push_back(nums[counter]);
                counter++;
                counter = counter % nums.size();
            }
            nums.clear();
            nums = ans;
        }
    }

    // Inplace
    void rotate(vector<int>& nums, int k) {
        if (!nums.empty()) {
            k %= nums.size();
            reverse(nums.begin(), nums.begin() + nums.size() - k);
            reverse(nums.begin() + nums.size() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};