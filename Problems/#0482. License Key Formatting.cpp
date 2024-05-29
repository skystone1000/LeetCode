// #0482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/description/

#include<bits/stdc++.h>
using namespace std;

// Method 1
// Time Complexity: O(N) - Space Complexity: O(1)
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int groupSize = 0;
        string finalString = "";

        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i] != '-'){
                finalString += toupper(s[i]);
                groupSize++;
                if(groupSize == k){
                    finalString += "-";
                    groupSize = 0;
                }
            }
        }

        if(finalString.size() > 0 && finalString.back() == '-')
            finalString.pop_back();

        reverse(finalString.begin(), finalString.end());
        return finalString;
    }
};