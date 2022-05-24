// #0032. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/

#include<bits/stdc++.h>
using namespace std;


// Method 1 - Stack
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 7.3 MB, less than 42.55% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
    int longestValidParentheses(string s) {
        // Length of maximum valid parentheses
        int MAX = 0;  
        stack<int> stk;
        // Bottom of stack=>always hold index preceding to potential start of valid parentheses
        stk.push(-1);
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '(') 
                stk.push(i);            
            else{                
                stk.pop();
                if(stk.empty()) 
                    stk.push(i);
                else 
                    MAX = max(MAX, i - stk.top());
            }        
        return MAX;
    }
};