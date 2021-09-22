// May Challenge 2021 - Day 3 - #1480. Running Sum of 1d Array
// #1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/

// Method 1 (New array solution)
// Time complexity: O(n)
// Space complexity: O(n) - But leetcode does not consider this 
// if it is the array to be returned so it may say O(1).

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0)
                ans[i] = nums[i];
            else
                ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
};

// Method 2 (In place solution)
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i-1] + nums[i];
        }
        return nums;
    }
};