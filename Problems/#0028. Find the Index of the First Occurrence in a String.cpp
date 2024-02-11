// LeetCode Arrays & Strings - 8
// #0028. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

// Mehtod 2 - KMP - String pattern matching algo
class Solution {
private:
    vector<int> preprocess(string& s) {
        vector<int> kmp(s.length()); 
        int i = 1, m = 0;
        kmp[0] = 0;
        while (i < s.length()) {
            if (s[i] == s[m]) {
                kmp[i++] = ++m;
            } else if (m > 0) {
                m = kmp[m - 1];
            } else {
                kmp[i++] = 0;
            }
        }
        return kmp;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        vector<int> kmp = preprocess(needle);
        for (int i = 0, j = 0; i < haystack.length();) {
            if (needle[j] == haystack[i]) { ++i; ++j; }
            if (j == needle.length()) return i - j;
            if (i < haystack.length() && needle[j] != haystack[i]) {
                if (j > 0) j = kmp[j - 1];
                else ++i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()) return -1;
        for (int i = 0; i + needle.length() < haystack.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};