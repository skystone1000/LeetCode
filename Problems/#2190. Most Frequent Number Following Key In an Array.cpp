// 2190. Most Frequent Number Following Key In an Array
// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> mp;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == key){
                mp[nums[i+1]]++;
            }
        }
        
        int target,maxVal = 0;
        for(auto ele:mp){
            if(ele.second > maxVal){
                maxVal = ele.second;
                target = ele.first;
            }
        }
        return target;
    }
};