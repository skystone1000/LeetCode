// Company Amazon
// 01 #0001 Two Sum
// https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;

// Approach 3 - Hashmap - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            if(seen.find(target - nums[i]) != seen.end()){
                ans.push_back(i);
                ans.push_back(seen[target - nums[i]]);
                return ans;
            }else{
                seen.insert({nums[i],i});
            }
        }
        return ans;
    }
};

/*
// Approach 2 - Sorting - O(nlogn)
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

// Approach 1 - Brute Force - O(n^2)
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
*/