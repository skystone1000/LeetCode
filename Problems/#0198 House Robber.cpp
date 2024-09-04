// #0198. House Robber
// https://leetcode.com/problems/house-robber/
// Tags - Amazon, Google

#include<bits/stdc++.h>
using namespace std;

// Approach 3: Optimized Dynamic Programming
// Time Complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);

        int max2ndPrev = nums[0];
        int maxPrev = max(nums[0],nums[1]);
        int maxCurr = -1;

        for(int i=2;i<nums.size();i++){
            maxCurr = max(max2ndPrev + nums[i], maxPrev);
            max2ndPrev = maxPrev;
            maxPrev = maxCurr;
        }
        return maxPrev;
    }
};



// Approach 2: Dynamic Programming
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        map<int,int> maxValues;

        maxValues[0] = nums[0];
        maxValues[1] = max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            maxValues[i] = max(nums[i] + maxValues[i-2], maxValues[i-1]);
        }
        return maxValues[nums.size()-1];
    }
};


// Approach 1: Recursion with Memoization
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    map<int,int> maxValue;
    int rob(vector<int>& nums) {
        return solve(nums.size()-1, nums);
    }

    int solve(int n, vector<int>& nums){
        // Base Case
        if(n == 0)
            return nums[0];
        if(n == 1)
            return max(nums[0], nums[1]);
        
        if(maxValue.find(n) == maxValue.end())
            maxValue[n] = max(solve(n-1, nums), solve(n-2, nums) + nums[n]);

        return maxValue[n];
    }
};
