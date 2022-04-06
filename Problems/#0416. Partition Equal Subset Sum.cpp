// LC - #0416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
// Aditya Verma - DP Playlist 08 Equal Sum Partition

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum % 2 == 1)
            return false;
        
        // Find a subset whose sum is half of total sum
        return subsetSum(nums, sum/2);        
    }
    
    bool subsetSum(vector<int> &nums, int total){
        int n = nums.size();
        int w = total;
        bool t[n+1][w+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0) t[i][j] = false;
                if(j==0) t[i][j] = true;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(nums[i-1] <= j)
                    t[i][j] = max(t[i-1][j-nums[i-1]] , t[i-1][j]);
                else if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][w];
    }
};