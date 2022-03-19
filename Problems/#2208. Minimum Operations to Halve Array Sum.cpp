// 2208. Minimum Operations to Halve Array Sum
// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double> q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            sum += nums[i];
        }
        
        int operations = 0;
        double currSum = sum;
        
        while(currSum > sum/2){
            double top = q.top();
            q.pop();
            currSum -= top/2;
            q.push(top/2);
            operations++;
            
        }
        return operations;
    }
};