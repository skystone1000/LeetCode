// Hash Table
// 03 #0217 Contains Duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> arr;
        for(int i=0;i<nums.size();i++){
            if(arr.count(nums[i]) > 0)
                return true;
            arr.insert(nums[i]);
        }
        return false;
    }
};
