// Company Amazon
// 02 #0136 Single Number
// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Method 1
        // unordered_map<int,int> freq;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        // }
        
        // for(auto ele:freq){
        //     cout<<ele.first<<" "<<ele.second<<endl;
        //     if(ele.second != 2){
        //         return ele.first;
        //     }
        // }
        // return -1;
        
        // Method 2
        int num = nums[0];
        for(int i=1; i <nums.size(); i++)
        {
            num ^= nums[i];
        }
        return num;
        
        // Method 3
        // return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
            
    }
};

