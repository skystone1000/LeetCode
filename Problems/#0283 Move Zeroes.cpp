// LeetCode arrays 12
// #0283 Move Zeroes    
// https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Extra Space
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int numZeroes = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }else{
                numZeroes++;
            }
        }

        while (numZeroes--) {
            ans.push_back(0);
        }

        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};

// Method 2 - optimal 2 pointer approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[lastNonZeroFoundAt] = nums[i];
                lastNonZeroFoundAt++;
            }
        }
        
        for(int i=lastNonZeroFoundAt;i<nums.size();i++)
            nums[i] = 0;        
    }
};

// Method 3 - Swapping
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        for (int cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt], nums[cur]);
                lastNonZeroFoundAt++;
            }
        }
    }
};

// Method 4 - Inbuilt Functions
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroCount++;
            }
        }
        
        nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
        
        for(int i=0;i<zeroCount;i++){
            nums.push_back(0);
        }
    }
};

