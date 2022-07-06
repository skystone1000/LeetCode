// LeetCode arrays 10
// #1299 Replace Elements with Greatest Element on Right Side  
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Brute Force 
// Time - O(n^2)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i=0;i<arr.size()-1;i++){
            int maxCurr = INT_MIN;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j] > maxCurr)
                    maxCurr = arr[j];
            }
            arr[i] = maxCurr;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};

// Method 2 - Reverse traversal (inplace)
// Time - O(n)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxCurr = -1;
        for(int i=arr.size()-1;i>=0;i--){
            int currEle = arr[i];
            arr[i] = maxCurr;
            if(maxCurr < currEle)
                maxCurr = currEle;
        }
        return arr;
    }
};