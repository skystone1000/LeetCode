// 2200. Find All K-Distant Indices in an Array
// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int K) {
        int i, j, k, n = a.size();
        vector<int> res;
        for (i = 0; i < n; ++i){
            for (j = 0; j < n; ++j)
                if (labs(i - j) <= K && a[j] == key) 
                    break;
            if (j < n) res.push_back(i);
        }
        
        return res;
    }
};


// Contest Solution
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> keyVec;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == key)
                keyVec.insert(i);
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(auto ele: keyVec){
                // cout<<i<<" "<<i-ele<<" "<<ele-i<<endl;
                if((i-ele <= k && i-ele >= 0) || (ele-i <=k && ele-i >= 0) ){
                    // cout<<"here"<<endl;
                    ans.push_back(i);     
                    break;
                }
            }
        }
        return ans;
    }
};