// #0003. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

// Method 2 - Hashset O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i=0, j=0, n=s.size(), ans = 0;
        
        while(i<n && j<n){
            // If current character is not found in set
            if(set.find(s[j]) == set.end()){
                set.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            }  else { // If current character is found in set
                set.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

/*
// Method 1 - Brute Force (TLE)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        
        int maxlen = 1;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(i==j) continue;
                set<char> temp;
                for(int k=i;k<=j;k++){
                    temp.insert(s[k]);
                }
                if(temp.size() == j-i+1){
                    if(maxlen < j-i+1){
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return maxlen;
    }
};
*/