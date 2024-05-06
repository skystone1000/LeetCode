// #0300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/description/
// Company Tag - Apple,Amazon,Meta,Google,Microsoft,Walmart Labs, MongoDB

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Improve With Binary Search
// Time complexity: O(N⋅log(N)), Space complexity: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                int j = binarySearch(sub, num);
                sub[j] = num;
            }
        }

        return sub.size();
    }

private:
    int binarySearch(const vector<int>& sub, int num) {
        int left = 0;
        int right = sub.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (sub[mid] == num) {
                return mid;
            }

            if (sub[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};


// Binary Search with lower_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                // Replace the first element in sub which is >= num
                auto it = lower_bound(sub.begin(), sub.end(), num);
                *it = num;
            }
        }

        return sub.size();
    }
};



// Approach 2: Intelligently Build a Subsequence
// Time complexity: O(N^2), Space complexity: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > sub.back()) {
                sub.push_back(num);
            } else {
                // Replace the first element in sub which is >= num
                // Linear Search here -> optimized in next approach with binary search
                int j = 0;
                while (num > sub[j]) {
                    j += 1;
                }
                sub[j] = num;
            }
        }

        return sub.size();
    }
};


// Approach 1: Dynamic Programming
// Time complexity: O(N^2), Space complexity: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);  // Every element is an LIS of at least length 1

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
