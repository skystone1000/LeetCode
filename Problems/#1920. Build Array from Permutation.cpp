// #1920. Build Array from Permutation
// https://leetcode.com/problems/build-array-from-permutation/description

#include<bits/stdc++.h>
using namespace std;


// Approach 2: Build In Place
// Time complexity: O(n), Space complexity: O(1).
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // Build the final value on the first iteration
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        // Modified to final value on the second iteration
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
};


// Approach 1: Build As Required
// Time complexity: O(n), Space complexity: O(n).
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};