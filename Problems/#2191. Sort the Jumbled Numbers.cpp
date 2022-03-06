// 2191. Sort the Jumbled Numbers
// https://leetcode.com/problems/sort-the-jumbled-numbers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> pr;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            string newNum = "";
            if(curr == 0) newNum = to_string(mapping[curr]);
            while(curr>0){
                int digit = curr%10;
                // Adding digit first to create reverse
                newNum = to_string(mapping[digit]) + newNum;
                curr = curr/10;
            }
            pr.push_back({stoi(newNum),nums[i]});
            // cout<<newNum<<" "<<nums[i]<<endl;
        }
        
        // Stable sort -> maintains order if elements are equal
        stable_sort(pr.begin(),pr.end(), [] (const pair<int, int> p1, const pair<int, int> p2) 
                    {return p1.first < p2.first;}
                   );
        vector<int> ans;
        for(auto ele:pr){
            // cout<<ele.first<<" "<<ele.second<<endl;
            ans.push_back(ele.second);
        }
        return ans;
    }
};