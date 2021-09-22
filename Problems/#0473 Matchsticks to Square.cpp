// June Challenge 2021 - Day 15 - #0473. Matchsticks to Square
// #0473. Matchsticks to Square
// https://leetcode.com/problems/matchsticks-to-square/

#include<bits/stdc++.h>
using namespace std;

// Method 1 (Recursion / Backtracking)
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        
        if(matchsticks.size() < 4 || sum % 4)
            return false;
        
        vector<int>visited(matchsticks.size(), false);
        return backtrack(matchsticks, visited, sum/4, 0, 0, 4);
    }
    
    bool backtrack(vector<int>& matchsticks, vector<int> visited, int target, int curr_sum, int i, int k){
        // If k==1 then we found all subsets
        if(k==1)
            return true;
        
        // First subset found, check for next starting from curr_sum=0
        if(curr_sum == target)
            return backtrack(matchsticks, visited, target, 0, 0, k-1);
        
        for(int j=i; j<matchsticks.size(); j++){
            if(visited[j] || curr_sum + matchsticks[j] > target)
                continue;
            
            visited[j] = true;
            if(backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, k))
                return true;
            visited[j] = false;
        }
        
        return false;
    }
};