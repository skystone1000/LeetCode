// LeetCode Arrays & Strings - 8
// #0028 Implement strStr()
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

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