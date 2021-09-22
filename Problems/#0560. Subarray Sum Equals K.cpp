// Company Amazon
// AIE 10.4 #0560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        
        int currSum = 0, count = 0;
        unordered_map<int,int> mymap;
        
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            
            if(currSum == k)
                count++;
            if(mymap.find(currSum - k) != mymap.end())
                count += mymap[currSum-k];
            
            mymap[currSum]++;
        }
        
        return count;
    }
};