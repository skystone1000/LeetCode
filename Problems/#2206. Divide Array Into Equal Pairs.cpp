// 2206. Divide Array Into Equal Pairs
// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto ele:mp){
            // cout<<ele.first<<" "<<ele.second<<endl;
            if(ele.second % 2 == 1)
                return false;
        }
        
        return true;
    }
};