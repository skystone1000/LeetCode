// #0047. Permutations II
// https://leetcode.com/problems/permutations-ii/

// Runtime: 68 ms, faster than 23.16% of C++ online submissions for Permutations II.
// Memory Usage: 9.1 MB, less than 65.84% of C++ online submissions for Permutations II.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    set<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;        
    }
    
    void solve(vector<int>& nums, int idx){
        if(idx > nums.size()-1){
            ans.insert(nums);
            return;
        }
        
        for(int i=idx; i<nums.size();i++){
            swap(nums[idx],nums[i]);
            solve(nums, idx+1);
            swap(nums[idx],nums[i]);
        }
    }
};

// Other solutions
// https://leetcode.com/problems/permutations-ii/discuss/933190/C%2B%2B-4-different-solutions-with-explanations-and-tips