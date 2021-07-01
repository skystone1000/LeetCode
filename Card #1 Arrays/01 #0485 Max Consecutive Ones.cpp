// LeetCode arrays 1
// #0485 Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max= 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
                continue;
            }else{
                if(count > max){
                    max = count;
                }
                count = 0;
            }
        }
        
        // Exit case with 1
        if(count > max){
            max = count;
        }
        return max;
        
    }
};