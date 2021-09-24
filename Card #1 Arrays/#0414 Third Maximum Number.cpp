// LeetCode arrays 16
// #0414 Third Maximum Number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        
        vector<int>::iterator ip;
        ip = unique(nums.begin(),nums.end());
        nums.resize(std::distance(nums.begin(), ip)); 
        
        for(int element:nums){
            cout<<element<<" ";
        }
        cout<<endl;
        if(nums.size() < 3){
            if(nums[0]>nums[1]){
                return nums[0];
            }else
                return nums[1];
        }
        
        return nums[2];
    }
};

