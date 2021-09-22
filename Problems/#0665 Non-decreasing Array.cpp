// May Challenge 2021 - Day 4 - #0665. Non-decreasing Array
// #0665. Non-decreasing Array
// https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int violation = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                
                if(violation == 1){
                    return false;
                }
                violation++;
               
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
                
            }
        }
        
        return true;
    }
};