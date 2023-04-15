// LeetCode arrays 7
// #0026 Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Extra space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> uniq;
        for(int i=0;i<nums.size();i++){
            uniq.insert(nums[i]);
        }
        
        int i=0;
        for(int ele:uniq){
            nums[i] = ele;
            i++;
        }
        return i;
    }
};

// Method 2 - Optimal Two pointer approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        
        int start = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[start] = nums[i];
                start++;
            }
        }
        
        return start;
    }
};

// Method 3 - STD functions
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator ip;
        
        ip = std::unique(nums.begin(),nums.end());
        nums.resize(std::distance(nums.begin(),ip));
        return nums.size();
    }
};

