// #1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Stack
// Time - O(N) , Space - O(N)
class Solution {
public:
    int maxDepth(string s) {
        int maximumDepth = 0;
        stack<char> st;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
                maximumDepth = max(maximumDepth , (int)st.size());
            }else if(ch == ')'){
                st.pop();
            }
        }
        return maximumDepth;
    }
};

// Approach 2 : Counter Variable
// Time - O(N) , Space - O(1)
class Solution {
public:
    int maxDepth(string s) {
        int maximumDepth = 0;
        int currDepth = 0;
        for(char ch : s){
            if(ch == '('){
                currDepth++;
                maximumDepth = max(maximumDepth , currDepth);
            }else if(ch == ')'){
                currDepth--;
            }
        }
        return maximumDepth;
    }
};
