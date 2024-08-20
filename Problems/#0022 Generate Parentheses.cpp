// June Challenge 2021 - Day 16 - #0022. Generate Parentheses
// #0022. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include<bits/stdc++.h>
using namespace std;

// Approach 3: Divide and Conquer
// Time complexity: O(4^n / sqrt(n)​)
// Space complexity: O(n)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>{""};
        }
        
        vector<string> answer;
        for (int leftCount = 0; leftCount < n; ++leftCount)
            for (string leftString : generateParenthesis(leftCount))
                for (string rightString : generateParenthesis(n - 1 - leftCount))
                    answer.push_back("(" + leftString + ")" + rightString);

        return answer;
    }
};


// Approach 3: Divide and Conquer (With set)
// Time complexity: O(4^n / sqrt(n)​)
// Space complexity: O(n)
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


// Approach 2: Backtracking, Keep Candidate Valid
// Time complexity: O(4^n / sqrt(n)​)
// Space complexity: O(n)
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


// Method 1 (Recursive Brute Force)
// Time complexity: O((2^2n)⋅n)
// Space complexity:
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

// Method 1 (Iterative Brute Force)
// Time complexity: O((2^2n)⋅n)
// Space complexity:
class Solution {
private:
    bool isValid(std::string pString) {
        int leftCount = 0;
        for (char p : pString) {
            if (p == '(') {
                leftCount++;
            } else {
                leftCount--;
            }
            if (leftCount < 0) {
                return false;
            }
        }
        return leftCount == 0;
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> answer;
        std::queue<std::string> queue;
        queue.push("");
        while (!queue.empty()) {
            std::string curString = queue.front();
            queue.pop();
            if (curString.length() == 2 * n) {
                if (isValid(curString)) {
                    answer.push_back(curString);
                }
                continue;
            }
            queue.push(curString + ")");
            queue.push(curString + "(");
        }
        return answer;
    }
};