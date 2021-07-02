// LeetCode Arrays & Strings - 16
// #0189 Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() > 1 && k != 0){ 
            vector<int> ans;
            if(k>nums.size())
                k = k % nums.size(); 
            int counter = nums.size() - k;
            for(int i=0;i<nums.size();i++){
                ans.push_back(nums[counter]);
                counter++;
                counter = counter % nums.size();
            }
            nums.clear();
            nums = ans;
        }
    }
};