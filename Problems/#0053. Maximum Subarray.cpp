// #0053. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
// Company tag - Amazon

#include<bits/stdc++.h>
using namespace std;

// Approach 5(2 in editorial): Dynamic Programming, Kadane's Algorithm
// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.size(); i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            currentSubarray = max(nums[i], currentSubarray + nums[i]);
            maxSubarray = max(maxSubarray, currentSubarray);
        }
        return maxSubarray;
    }
};

// Approach 4(3 in editorial): Divide and Conquer (Advanced)
// Time complexity: O(N⋅logN), Space complexity: O(logN)
class Solution {
private:
    vector<int> numsArray;

public:
    int maxSubArray(vector<int>& nums) {
        numsArray = nums;
        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return findBestSubarray(0, numsArray.size() - 1);
    }
    int findBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return INT_MIN;
        }
        int mid = (left + right) / 2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = max(bestLeftSum, curr);
        }
        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = max(bestRightSum, curr);
        }
        // The bestCombinedSum uses the middle element and the best
        // possible sum from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;
        // Find the best subarray possible from both halves.
        int leftHalf = findBestSubarray(left, mid - 1);
        int rightHalf = findBestSubarray(mid + 1, right);
        // The largest of the 3 is the answer for any given input array.
        return max(bestCombinedSum, max(leftHalf, rightHalf));
    }
};


// Approach 3: Recusion + memoization
// Time complexity: O(N), Space complexity: O(N)
class Solution {
    vector<int> nums;
    map<int,int> memo;
public:
    int maxSubArray(vector<int>& nums) {
        this->nums = nums;
        int result = INT_MIN;
        for(int i=0;i<nums.size();i++){
            result = max(result, dp(i));
        }
        return result;
    }

    int dp(int n){
        if(n == 0)
            return memo[0] = nums[0];

        if(!memo.count(n)){
            memo[n] = max(nums[n], dp(n-1)+nums[n]);
        }

        return memo[n];
    }
};



// Approach 2: Recursive solution (TLE)
// Time complexity: O(N^2), Space complexity: O(1)
class Solution {
    vector<int> nums;
public:
    int maxSubArray(vector<int>& nums) {
        this->nums = nums;
        int result = INT_MIN;
        for(int i=0;i<nums.size();i++){
            result = max(result, dp(i));
        }
        return result;
    }

    int dp(int n){
        if(n == 0)
            return  nums[0];

        return max(nums[n], dp(n-1)+nums[n]);
    }
};


// Approach 1: Optimized Brute Force (TLE)
// Time complexity: O(N^2), Space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_subarray = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int current_subarray = 0;
            for (int j = i; j < nums.size(); j++) {
                current_subarray += nums[j];
                max_subarray = max(max_subarray, current_subarray);
            }
        }
        return max_subarray;
    }
};


// Old Approach 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = INT_MIN, max_ending_here = 0; 
  
        for (int i = 0; i < n; i++) 
        { 
            max_ending_here = max_ending_here + nums[i]; 
            if (max_so_far < max_ending_here) 
                max_so_far = max_ending_here; 

            if (max_ending_here < 0) 
                max_ending_here = 0; 
        } 
        return max_so_far; 
    }
};