// LeetCode arrays 15
// #1051 Height Checker
// https://leetcode.com/problems/height-checker/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Sorting
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(),expected.end());
        int ans=0;
        for(int i=0;i<expected.size();i++){
            if(expected[i] != heights[i])
                ans++;
        }
        
        return ans;
    }
};

// method 2 - Frequency array
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heightFreq(101,0);
        
        for(int height:heights)
            heightFreq[height]++;
            
        int result=0, currHeight=0;
        for(int i=0;i<heights.size();i++){
            while(heightFreq[currHeight] == 0)
                currHeight++;
            if(currHeight != heights[i])
                result++;
            heightFreq[currHeight]--;
        }
        return result;
    }
};