// #0020 Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Company Tag - 10 Amazon
// Card Queue & Stack #6


#include<bits/stdc++.h>
using namespace std;


// Approach 1: Stack
// Time complexity : O(n), Space complexity : O(n)
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;
        for (char c : s) {
            if (matching.count(c)) {
                // If c is a closing bracket
                if (st.empty() || st.top() != matching[c])
                    return false;
                st.pop();
            } else {
                // If c is an opening bracket
                st.push(c);
            }
        }

        return st.empty();
    }
};



// Old Solution
class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<int> pending;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                pending.push(s[i]);
                // cout<<"Push "<<s[i]<<endl;
            }
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(pending.size() < 1) return false;
                // cout<<"Pop "<<s[i]<<endl;
                char check;
                if(pending.top() == '(') check = ')';
                if(pending.top() == '{') check = '}';
                if(pending.top() == '[') check = ']';
                if(check == s[i]){
                    
                    pending.pop();
                }else{
                    return false;
                }
            }
        }
        if(pending.size() == 0)
            return true;
        else 
            return false;
    }
};