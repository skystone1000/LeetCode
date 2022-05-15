// #0046. Permutations
// https://leetcode.com/problems/permutations/


#include<bits/stdc++.h>
using namespace std;


// Method 1 - Back tracking
// Runtime: 3 ms, faster than 78.03% of C++ online submissions for Permutations.
// Memory Usage: 8 MB, less than 38.00% of C++ online submissions for Permutations.
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;        
    }
    
    void solve(vector<int>& nums, int idx){
        if(idx > nums.size()-1){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size();i++){
            swap(nums[idx],nums[i]);
            solve(nums, idx+1);
            swap(nums[idx],nums[i]);
        }
    }
};


// Method 2 - using next_permutation
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
// Memory Usage: 7.6 MB, less than 78.49% of C++ online submissions for Permutations.
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        ans.push_back(num);

        while(next_permutation(num.begin(), num.end()))
            ans.push_back(num);
        return ans;
    }
};


// Method 3 - DFS
// https://leetcode.com/problems/permutations/discuss/18462/Share-my-three-different-solutions