// #0217 Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
// Cards - Hash Table

#include<bits/stdc++.h>
using namespace std;

// Approach #3 (Hash Table)
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return true;  // Equivalent to set.contains(x) in Java
            seen.insert(x);                 // Add x to the set
        }
        return false;
    }
};


// Approach #2 (Sorting)
// Time complexity: O(nlogn), Space complexity: O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) return true;  // Check adjacent elements
        }
        return false;
    }
};


// Approach #1 (Naive Linear Search) [Time Limit Exceeded]
// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};
