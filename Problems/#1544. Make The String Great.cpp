// #1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Iteration
// Time complexity: O(n^2), Space complexity: O(n)
class Solution {
public:
    string makeGood(string s) {
        while (s.size() > 1) {
            bool isStringUpdated = false;
            
            for (int i = 0; i < s.size() - 1; ++i) {
                char currChar = s[i], nextChar = s[i + 1];
                
                if (abs(currChar - nextChar) == 32) {
                    s = s.substr(0, i) + s.substr(i + 2);
                    isStringUpdated = true;
                    break;
                }
            }
            
            if (isStringUpdated == false)
                break;
        }
        return s;
    }
};

// Approach 2: Recursion
// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution {
public:
    string makeGood(string s) {
        if (s.size() < 2)
            return s;

        for (int i = 0; i < s.size() - 1; ++i) {
            char currChar = s[i], nextChar = s[i + 1];

            if (abs(currChar - nextChar) == 32) {
                s = s.substr(0, i) + s.substr(i + 2);
                return makeGood(s);
            }
        }

        return s;
    }
};

// Approach 3: Stack
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    string makeGood(string s) {
        vector<char> stack;
        for (char curr : s) {
            if (!stack.empty() && abs(stack.back() - curr) == 32)
                stack.pop_back(); 
            else
                stack.push_back(curr);
        }
        string ans(stack.begin(), stack.end());
        return ans;
    }
};

// Approach 4: Two pointers, in-place modify
// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    string makeGood(string s) {
        int end = 0;
        for (int cur = 0; cur < s.size(); ++cur) {
            if (end > 0 && abs(s[cur] - s[end - 1]) == 32)
                end--;
            else {
                s[end] = s[cur];
                end++;
            }
        }
        
        return s.substr(0, end);  
    }
};