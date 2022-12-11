// Company Amazon
// 35 #0014. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Character wise comparision of all strings with first string
// Vertical Scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        
        string ans = "";
        int count = 0;
        for(char ch:strs[0]){
            for(string curr:strs){
                if(curr[count] != ch){
                    return ans;
                }
            }
            ans += ch;
            count++;
        }
        
        return ans;
    }
};

// Method 2 - Character wise comparision of all strings with smallest string
// Vertical Scanning - Slightly better than first method
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minLength = strs[0].size();
        for(int i=0;i<strs.size();i++){
            if(strs[i].size() < minLength){
                minLength = strs[i].size();
            }
        }

        for(int i=0;i<minLength;i++){
            char currChar = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i] != currChar){
                    return ans;
                }
            }
            ans += currChar;
        }
        return ans;
    }
};


// Same as approach 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string ans;
        
        for(int i=0;i<strs[0].size();i++){
            char check = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i>strs[j].size() || check != strs[j][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};