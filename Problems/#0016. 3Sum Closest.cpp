// #0016. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/description/
// Company Tag - Amazon, Google

#include<bits/stdc++.h>
using namespace std;


/*
For an interview, we recommend focusing on the Two Pointers approach above. It's easier to get it right 
and adapt for other variations of 3Sum. Interviewers love asking follow-up problems like 3Sum Smaller!

If an interviewer asks you whether you can achieve O(1) memory complexity, you can use the selection sort 
instead of a built-in sort in the Two Pointers approach. It will make it a bit slower, though the overall 
time complexity will be still O(n2).
*/


// Approach 1: Two Pointers
// Time complexity: O(n^2), Space Complexity: from O(logn) to O(n), depending on the implementation of the sorting algorithm
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return target - diff;
    }
};


// Approach 2: Binary Search
// Time complexity: O(n^2logn), Space Complexity: from O(logn) to O(n), depending on the implementation of the sorting algorithm
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                auto it =
                    upper_bound(begin(nums) + j + 1, end(nums), complement);
                int hi = it - begin(nums), lo = hi - 1;
                if (hi < sz && abs(complement - nums[hi]) < abs(diff)) {
                    diff = complement - nums[hi];
                }
                if (lo > j && abs(complement - nums[lo]) < abs(diff)) {
                    diff = complement - nums[lo];
                }
            }
        }
        return target - diff;
    }
};