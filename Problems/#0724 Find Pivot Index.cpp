// LeetCode Arrays & Strings - 1
// #0724 Find Pivot Index  
// https://leetcode.com/problems/find-pivot-index/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Brute force

// Method 2 - Time => O(n) - Space => O(n) - Extra space 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> start;
        vector<int> end;
        int startSum=0,endSum=0;
        
        // Updating Start and end cumulative sums in reverse order
        for(int i=0;i<nums.size();i++){
            startSum += nums[i];
            start.push_back(startSum);
            endSum += nums[nums.size()-i-1];
            end.push_back(endSum);
        }
        reverse(end.begin(),end.end());
        
        for(int i=0;i<nums.size();i++){
            if(start[i] == end[i]){
                return i;
            }
        }
        return -1;
    }
};

// Method 3 - Alternative to method 2
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int leftSum=0,rightSum=0;
        while(i<j){
            leftSum+=nums[i++];
            rightSum+=nums[j--];
        }
        
        // TODO: Traverse towards the side where sum is more
    }
};