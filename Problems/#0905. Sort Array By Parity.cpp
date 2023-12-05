// Company Amazon
// 31 #0905. Sort Array By Parity
// LeetCode arrays 12
// https://leetcode.com/problems/sort-array-by-parity/

#include<bits/stdc++.h>
using namespace std;

// Approach 4: In-Place QuickSort
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]%2 > nums[j]%2){
                swap(nums[i],nums[j]);
            }
            if(nums[i]%2 == 0)
                i++;
            if(nums[j]%2 == 1)
                j--;
        }

        return nums;
    }
};


// Method 3 - Optimal 2 pointer approach
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int even = 0;
        for(int i=0;i<A.size();i++){
            if(A[i] % 2 == 0){
                swap(A[even], A[i]);
                even++;
            }
        }
        return A;
    }
};


// Method 2 - Extra space 1 Pass
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int start = 0, end = nums.size()-1; 
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2 == 0){
                ans[start] = nums[i];
                start++;
            }else{
                ans[end] = nums[i];
                end--;
            }
        }
        return ans;
    }
};

// Approach 1: Extra Space 2 pass
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++)
            if(nums[i]%2 == 0)
                ans.push_back(nums[i]);

        for(int i=0;i<nums.size();i++)
            if(nums[i]%2 == 1)
                ans.push_back(nums[i]);

        return ans;
    }
};

