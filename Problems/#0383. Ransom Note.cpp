// LeetCode Arrays & Strings - 1
// #0383. Ransom Note 
// https://leetcode.com/problems/ransom-note/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(char ch : magazine)
            count[ch - 'a']++;
        
        for(char ch : ransomNote)
            if(count[ch - 'a']-- <= 0)
                return false;
        
        return true;
    }
};