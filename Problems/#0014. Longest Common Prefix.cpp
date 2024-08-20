// Company Amazon
// 35 #0014. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Horizontal scanning
// S is the sum of all characters in all strings
// Time complexity : O(S), Space complexity : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            // We need prefix at start of string -> strs = ["c","acc","ccc"] -> expected ans ""
            while (strs[i].find(prefix) != 0) {
                // prefix not found -> reduce prefix size by 1
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        return prefix;
    }
};

// Approach 2: Vertical scanning
// Time complexity : O(S), Space complexity : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

// Approach 3: Divide and conquer / Recursion
// In the worst case we have n equal strings with length m
// Time complexity : O(S), Space complexity : O(m⋅logn)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

private:
    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(string left, string right) {
        int min = std::min(left.length(), right.length());
        for (int i = 0; i < min; i++) {
            if (left[i] != right[i]) return left.substr(0, i);
        }
        return left.substr(0, min);
    }
};

// Approach 4: Binary search
// Time complexity : O(S⋅logm), Space complexity : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = INT_MAX;
        for (string str : strs) minLen = min(minLen, (int)str.length());
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle))
                low = middle + 1;
            else
                high = middle - 1;
        }
        return strs[0].substr(0, (low + high) / 2);
    }

private:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++)
            if (strs[i].find(str1) != 0) return false;
        return true;
    }
};


// Check follow up in editorial about Tries