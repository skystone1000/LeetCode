// #1306. Jump Game III
// https://leetcode.com/problems/jump-game-iii/

#include<bits/stdc++.h>
using namespace std;

// Method 2 - BFS => 
// Time - O(N)
// Space - O(N)
class Solution {
public:
    bool canReach(vector<int>& arr, int cur) {
        queue<int> q;
        q.push(cur);
        while(q.size()){
            cur = q.front();
            q.pop();
            
            // Target Reached
            if(arr[cur] == 0)
                return true;
            
            // Already Visited
            if(arr[cur] < 0)
                continue;
            
            // Traverse forward if possible
            if(cur + arr[cur] < arr.size())
                q.push(cur + arr[cur]);
            
            // Traverse forward if possible
            if(cur - arr[cur] >= 0)
                q.push(cur - arr[cur]);
            
            // Mark current Index negative
            arr[cur] *= -1;
        }
        // Explored all array without reaching target
        return false;
    }
};

// Method 1 - DFS => 
// Time - O(N)
// Space - O(N)
/*
class Solution {
public:
    bool canReach(vector<int>& arr, int cur) {
        // out of bounds OR already visited ? return false
        if(cur < 0 || cur >= size(arr) || arr[cur] < 0) 
            return false;       

        // mark as visited by making -ve
        arr[cur] *= -1;        
        
        // return true if arr[cur] == 0 
        if(arr[cur] == 0)
            return true;
        
        // recurse for both possible jumps
        return canReach(arr, cur + arr[cur]) || canReach(arr, cur - arr[cur]);  
    }
};
*/