// #0246. Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;


// Approach 2 - Two Pointer
// Time - O(n), Space O(1)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for(int i=0;i<n;i++){
            // Check if elements before half of string and 
            // elements after half of string are reflections
            if(num[i] == '0' && num[n-i-1] == '0' || 
            num[i] == '1' && num[n-i-1] == '1' || 
            num[i] == '8' && num[n-i-1] == '8' ||
            num[i] == '6' && num[n-i-1] == '9' ||
            num[i] == '9' && num[n-i-1] == '6'){

            } else {
                return false;
            }
        }
        return true;
    }
};


// Approach 1 - Make a Rotated Copy
// Time complexity : O(N)
// Space complexity : O(N)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        // Mapping of digits after 180-degree rotation
        // Index:   0  1   2   3   4   5   6   7   8   9
        // Value:   0  1  -1  -1  -1  -1   9  -1   8   6
        vector<char> rotatedDigits = {'0', '1', '#', '#', '#', '#', '9', '#', '8', '6'};

        string rotatedString = "";

        // Traverse input string from the end (right to left)
        for (int i = num.size() - 1; i >= 0; --i) {
            char c = num[i];
            int idx = c - '0';  // Convert char digit to int index (e.g., '6' -> 6)

            // If the digit cannot be rotated, return false
            if (rotatedDigits[idx] == '#') return false;

            // Append the rotated digit
            rotatedString += rotatedDigits[idx];
        }

        // Check if rotated string equals the original number
        return rotatedString == num;
    }
};
    