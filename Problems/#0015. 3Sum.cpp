// #0015. 3Sum
// https://leetcode.com/problems/3sum/description/
// Company Tag - Amazon, Google

#include<bits/stdc++.h>
using namespace std;


// Approach 2: Sorting + Hashset
// Time Complexity: O(n^2), Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, res);
            }
        return res;
    }
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        unordered_set<int> seen;
        for (int j = i + 1; j < nums.size(); ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.count(complement)) {
                res.push_back({nums[i], complement, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            seen.insert(nums[j]);
        }
    }
};


// Approach 1: Sort + Two Pointers 
// Time Complexity: O(nlogn+n^2) => O(n^2), Space Complexity: from O(logn) to O(n) for sorting (Ignore output)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSumII(nums, i, res);
            }
        return res;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                res.push_back({nums[i], nums[lo++], nums[hi--]});
                while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
            }
        }
    }
};


// Approach 3: Hash with Triplet Sorting for Duplicate Elimination (Slower than initial 2 approaches)
// Time Complexity: O(n^2), Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_set<int> dups;
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i)
            if (dups.insert(nums[i]).second) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    int complement = -nums[i] - nums[j];
                    auto it = seen.find(complement);
                    if (it != end(seen) && it->second == i) {
                        vector<int> triplet = {nums[i], nums[j], complement};
                        sort(begin(triplet), end(triplet));
                        res.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
        return vector<vector<int>>(begin(res), end(res));
    }
};