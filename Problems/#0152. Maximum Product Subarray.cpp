// #0152. Maximum Product Subarray
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Dynamic Programming
// Time complexity : O(N)
// Space complexity : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            // Update max_so_far after updates to min_so_far to avoid
            // overwriting it
            max_so_far = temp_max;
            // Update the result with the maximum product found so far
            result = max(max_so_far, result);
        }

        return result;
    }
};


// Approach 2 - Recursive/Backtracking
// Time complexity : O(N)
// Space complexity : O(N)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0];
        helper(nums, nums.size() - 1, globalMax);
        return globalMax;
    }

private:
    // Returns {maxProdEndingHere, minProdEndingHere}
    pair<int, int> helper(vector<int>& nums, int i, int& globalMax) {
        if (i == 0) {
            globalMax = max(globalMax, nums[0]);
            return {nums[0], nums[0]};
        }

        auto prev = helper(nums, i - 1, globalMax);
        int curr = nums[i];

        int maxProd = max({curr, curr * prev.first, curr * prev.second});
        int minProd = min({curr, curr * prev.first, curr * prev.second});

        globalMax = max(globalMax, maxProd);
        return {maxProd, minProd};
    }
};



// Approach 1: Brute Force (Python TLE)
// Time complexity : O(N^2)
// Space complexity : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int accu = 1;
            for (int j = i; j < nums.size(); j++) {
                accu *= nums[j];
                result = max(result, accu);
            }
        }
        return result;
    }
};
