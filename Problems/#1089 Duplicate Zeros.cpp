// LeetCode arrays 4
// #1089 Duplicate Zeros
// https://leetcode.com/problems/duplicate-zeros/

#include<bits/stdc++.h>
using namespace std;

// Method 2 (Creating new array)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(ans.size() == arr.size())
                break;
            if(arr[i] == 0){
                ans.push_back(0);
                ans.push_back(0);
            } else {
                ans.push_back(arr[i]);
            }
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i] = ans[i];
        }
    }
};

// Method 1 (TLE)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                arr.insert( arr.begin() + i , 0 );
            }
        }
    }
};