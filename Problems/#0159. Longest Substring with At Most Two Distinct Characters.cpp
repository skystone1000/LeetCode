// #0159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        size_t n = s.length();
        if (n < 3) {
            return n;
        }

        // sliding window left and right pointers
        int left = 0, right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        map<char, int> hashmap;

        int max_len = 2;

        while (right < n) {
            // when the sliding window contains less than 3 characters
            hashmap[s[right]] = right;
            right++;

            // slidewindow contains 3 characters
            if (hashmap.size() == 3) {
                int del_idx = INT_MAX;
                for (pair<char, int> element : hashmap) {
                    del_idx = min(del_idx, element.second);
                }
                // delete the leftmost character
                hashmap.erase(s[del_idx]);
                left = del_idx + 1;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};

// Approach 1
// Time to solve - 25:09
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char,int> window;
        int maxWindow = 0;
        int left = 0, right = 0;
        for(;right<s.size();right++){
            window[s[right]]++;
            if(window.size()>2){
                maxWindow = max(maxWindow, right-left);
                window[s[left]]--;
                if(window[s[left]] < 1)
                    window.erase(s[left]);
                left++;
            }
        }
        return max(maxWindow, right-left);
    }
};