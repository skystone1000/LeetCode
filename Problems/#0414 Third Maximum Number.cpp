// LeetCode arrays 16
// #0414 Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Hastset (3 elements set so constant space)
// O(n) - time
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for(int num:nums){
            top3.insert(num);
            if(top3.size() > 3)
                top3.erase(top3.begin());
        }
        
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};

// Method 2 - Three variables
// O(n) - time
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
        for (int num : nums) {
            if (num == one || num == two || num == three)
                continue;
            
            if (num > one) {
                three = two;
                two = one;
                one = num;
            } else if (num > two) {
                three = two;
                two = num;
            } else if (num > three) {
                three = num;
            }
        }
        return three == LONG_MIN ? one : three;
    }
};


// Method 3 - In built Functions
// O(nlogn) time as sorting
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        
        vector<int>::iterator ip;
        ip = unique(nums.begin(),nums.end());
        nums.resize(std::distance(nums.begin(), ip)); 
        
        if(nums.size() < 3){
            if(nums[0]>nums[1]){
                return nums[0];
            }else
                return nums[1];
        }
        
        return nums[2];
    }
};

