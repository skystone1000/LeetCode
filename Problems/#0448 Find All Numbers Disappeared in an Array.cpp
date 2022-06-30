// LeetCode arrays 17
// #0448 Find All Numbers Disappeared in an Array    

#include<bits/stdc++.h>
using namespace std;

// All Solutions - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/1583736/C%2B%2BPython-All-6-Solutions-w-Explanations-or-Binary-Search%2B-Hashset-%2B-2x-O(1)-Space-Approach

// Method 1 - Extra space O(n), time - O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> elements(100000,1);
        int maxele = 0;
        for(int i=0;i<nums.size();i++){
            elements[nums[i]]--;
            if(nums[i] > maxele) maxele = nums[i];
        }
        
        // sometimes max element is missing
        if(maxele < nums.size())
            maxele = nums.size();
        
        vector<int> ans;
        // maxele+1 bcz 1 based indexing
        for(int i=1;i<maxele+1;i++){
            if(elements[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};

// Method 2 - Space O(1), time O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            // -1 as 1 based indexing
            int val = abs(nums[i]) - 1;
            if (nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};