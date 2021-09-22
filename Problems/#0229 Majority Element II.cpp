// June Challange Day 22
// #0229 Majority Element II  

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> freq;
        for(auto x:nums){
            freq[x]++;
        }
        
        int n = nums.size();
        vector<int> ans;
        for(auto ele:freq){
            if(ele.second > n/3){
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};