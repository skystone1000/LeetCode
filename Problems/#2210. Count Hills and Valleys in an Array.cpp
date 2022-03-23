// 2210. Count Hills and Valleys in an Array
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int countHillValley(vector<int>& arr) {
        vector<int> nums;
        int prev = 0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i] != arr[i+1]){
                nums.push_back(arr[i]);
                // cout<<arr[i]<<" ";
                prev = arr[i];
            }
            
            if(i == arr.size()-2 && prev != arr[i+1]){
                nums.push_back(arr[i+1]);
                // cout<<arr[i+1]<<" ";
            }
        }
        
        int count = 0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                count++;
            }else if(nums[i-1] > nums[i] && nums[i] < nums[i+1]){
                count++;
            }
        }
        return count;
    }
};