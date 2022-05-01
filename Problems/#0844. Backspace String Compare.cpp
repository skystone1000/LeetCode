// #0844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/submissions/

#include<bits/stdc++.h>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6.1 MB, less than 88.17% of C++ online submissions for Backspace String Compare.
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sf = "", tf = "";
        stack<char> st;

        // First String
        for(int i=0;i<s.size();i++){
            if(s[i] != '#')
                st.push(s[i]);
            else if(!st.empty())
                st.pop();
        }
        
        while(!st.empty()){
            sf += st.top();
            st.pop();
        }
        
        // Second String
        for(int i=0;i<t.size();i++){
            if(t[i] != '#')
                st.push(t[i]);
            else if(!st.empty())
                st.pop();
        }
        
        while(!st.empty()){
            tf += st.top();
            st.pop();
        }
        
        // Comparing
        if(sf == tf)
            return true;
        else
            return false;
    }
};