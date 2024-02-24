// #0091. Decode Ways
// https://leetcode.com/problems/decode-ways/description/
// Company tag - Google, Amazon, Microsoft

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Iterative, Constant Space
// Time Complexity: O(N), Space Complexity: O(1)
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (size_t i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 and two_digit <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }
        return one_back;
    }
};



// Approach 2: Iterative Approach
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    int numDecodings(string s) {
        // DP array to store the subproblem results
        vector<int> dp(s.length() + 1);
        dp[0] = 1;

        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s[0] == '0' ? 0 : 1;

        for (size_t i = 2; i < dp.size(); i++) {
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int two_digit = stoi(s.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};


// Approach 1: Recursive Approach with Memoization
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') return 0;

        // Reach the end of the string, Return 1 for success.
        if (index == str.length() || index == str.length() - 1) return 1;
        
        int ans = recursiveWithMemo(index + 1, str);
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        return memo[index] = ans;
    }

    int numDecodings(string s) { return recursiveWithMemo(0, s); }
};