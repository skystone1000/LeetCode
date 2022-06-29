// LeetCode arrays 12
// #0283 Move Zeroes    
// https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - optimal 2 pointer approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int updated = 0, curr = 0, zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[updated] = nums[i];
                updated++;
            }else {
                zeroCount++;
            }
        }
        
        for(int i=nums.size()-zeroCount;i<nums.size();i++)
            nums[i] = 0;        
    }
};

// Method 2 - Inbuilt Functions
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroCount++;
            }
        }
        
        nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
        
        for(int i=0;i<zeroCount;i++){
            nums.push_back(0);
        }
    }
};