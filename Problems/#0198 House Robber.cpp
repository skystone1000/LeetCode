// Company Amazon
// 25 #198. House Robber
// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        
        vector<int> arr(nums.size());
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        for(int i=2;i<nums.size();i++){
            arr[i] = max(nums[i] + arr[i-2], arr[i-1]);
        }
        
        return arr[nums.size() - 1];
    }
};