// June Challenge 2021 - Day 16 - #0022. Generate Parentheses
// #0022. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include<bits/stdc++.h>
using namespace std;

// Method 1 (Brute Force)
class Solution {
public:
    vector <string> ans;
    bool valid(string a){
        int balance = 0;
        for (char c: a) {
            if (c == '(') 
                balance++;
            else 
                balance--;
            if (balance < 0) return false;
        }
        return (balance == 0);
    }
    
    void brackets(int i, int n, string a){
        if(i==2*n){
            if(valid(a))
                ans.push_back(a);
            return;
        }
        a.push_back('(');
        brackets(i+1,n,a);
        a.pop_back();
        a.push_back(')');
        brackets(i+1,n,a);
    }
    
    vector<string> generateParenthesis(int n) {
        brackets(0,n,"");
        return ans;
    }
};

// Method 2 (Recursion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Initializing the required variables
        vector<string> v;
        int close = n;
        int open = n;
        string op = "";

        // Calling the recursive function
        solve(open, close, op, v);
        return v;
    }
    
    void solve(int open, int close, string op, vector<string>& v){
        // Base Condition
        if(open == 0 && close == 0){
            v.push_back(op);
            return;
        }

        // We are getting opening bracket always (unless zero)
        if(open != 0){
            string op1 = op;
            op1 += "(";
            // Recursing further 
            solve(open - 1, close, op1, v);
        }

        // Closing Bracket Choice
        if(close > open){
            string op2 = op;
            op2 += ")";
            // Recursing further
            solve(open, close - 1, op2, v);
            return;
        }
    }
};


// Method 3
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> ans;
        if (n == 0) {
            ans.insert("");
        } else {
            for (int c = 0; c < n; ++c)
                for (string left: generateParenthesis(c))
                    for (string right: generateParenthesis(n-1-c))
                        ans.insert("(" + left + ")" + right);
        }
        
        vector<string> result;
        for(string ele:ans){
            result.push_back(ele);
        }
        return result;
    }
};