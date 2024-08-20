// #0001 Two Sum
// https://leetcode.com/problems/two-sum/
// Company Tag - 01 Amazon, Google

#include<bits/stdc++.h>
using namespace std;

// Approach 4 - Hashmap One pass 
// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};

// Approach 3: Two-pass Hash Table
// Time Complexity: O(n), Space Complexity: O(n) 
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }
        // If no valid pair is found, return an empty vector
        return {};
    }
};


// Approach 2 - Sorting - 
// Time Complexity: O(nlogn), Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        
        vector<int> ans;
        sort(temp.begin(), temp.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(temp[i].first + temp[j].first == target){
                ans.push_back(temp[i].second);
                ans.push_back(temp[j].second);
                return ans;
            } else if(temp[i].first + temp[j].first < target){
                i++;
            } else{
                j--;
            }
        }
        return ans;
    }
};

// Approach 1 - Brute Force
// Time Complexity: O(n^2), Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    if(nums[i]+nums[j] == target){
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};