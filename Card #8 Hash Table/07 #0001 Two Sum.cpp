// Hash Table
// 07 #0001 Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp.insert({nums[i],i});
            
            int complement = target - nums[i];
            if(mp.count(complement) != 0){
                if(i != mp[complement]){
                    ans.push_back(i);
                    ans.push_back(mp[complement]);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};


/*
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert({nums[i],i});
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(mp.count(complement) != 0){
                if(i != mp[complement]){
                    ans.push_back(i);
                    ans.push_back(mp[complement]);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
*/
    
/*
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
*/