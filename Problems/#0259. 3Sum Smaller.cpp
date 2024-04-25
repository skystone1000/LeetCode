// #0259. 3Sum Smaller
// https://leetcode.com/problems/3sum-smaller/description/
// Company Tag - Amazon, Google

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Two Pointers
// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] < target - nums[k]) {
                    ans += j - i;
                    i += 1;
                } else {
                    j -= 1;
                }
            }
        }
        return ans;
    }
};


// Approach 2: Binary Search
// Time complexity: O((n^2)logn), Space complexity: O(1)



// Approach 1: Brute Force
// Time complexity: O(n^3), Space complexity: O(1)