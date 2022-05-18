// #1679. Max Number of K-Sum Pairs
// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include<bits/stdc++.h>
using namespace std;

// Runtime: 289 ms, faster than 16.94% of C++ online submissions for Max Number of K-Sum Pairs.
// Memory Usage: 67.8 MB, less than 40.33% of C++ online submissions for Max Number of K-Sum Pairs.

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int operations = 0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(k-nums[i]) != mp.end()){
                mp[k-nums[i]]--;
                if(mp[k-nums[i]] == 0)
                    mp.erase(k-nums[i]);
                operations++;
            }else{
                mp[nums[i]]++;
            }
        }
        return operations;
    }
};