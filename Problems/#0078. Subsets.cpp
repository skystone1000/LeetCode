// Company Amazon
// 36 #078. Subsets
// https://leetcode.com/problems/subsets/


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        generateSubsets(nums, 0, vector<int>(), subsets);
        return subsets;
    }
    
    void generateSubsets(vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& subsets){
        subsets.push_back(vector<int>(curr));
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            generateSubsets(nums, i+1, curr, subsets);
            curr.pop_back();
        }
        
    }
};