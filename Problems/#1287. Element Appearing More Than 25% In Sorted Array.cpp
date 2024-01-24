// #1287. Element Appearing More Than 25% In Sorted Array
// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> freq;
        int maxVal = 0;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
            if(maxVal < freq[arr[i]])
                maxVal = freq[arr[i]];
        }

        for(pair curr: freq){
            if(curr.second == maxVal)
                return curr.first;
        }

        return 0;
    }
};