// #0777. Swap Adjacent in LR String
// https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Two Pointers
// Time Complexity: O(N), where N is the length of start and end.
// Space Complexity: O(1)
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();

        // Count the difference of X's in start and end
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'X') count++;     // +1 for 'X' in start
            if (end[i] == 'X') count--;       // -1 for 'X' in end
        }
        if (count != 0) return false; // Unequal number of Xs → can't transform

        int i = 0, j = 0;
        while (i < n && j < n) {
            // Skip all 'X' in start
            while (i < n && start[i] == 'X') i++;
            // Skip all 'X' in end
            while (j < n && end[j] == 'X') j++;
            // If we reached the end in one string but not the other
            if (i == n || j == n)
                return i == n && j == n;

            if (start[i] != end[j]) return false;

            // 'L' can only move left, so index in start must be ≥ index in end
            if (start[i] == 'L' && i < j) return false;
            // 'R' can only move right, so index in start must be ≤ index in end
            if (start[i] == 'R' && i > j) return false;

            i++;
            j++;
        }

        return true;
    }
};


// Approach 1: Invariant
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    bool canTransform(string start, string end) {
        // Remove all 'X' and compare if remaining L and R sequence matches
        string s_no_x, e_no_x;
        for (char c : start) if (c != 'X') s_no_x += c;
        for (char c : end) if (c != 'X') e_no_x += c;
        if (s_no_x != e_no_x)
            return false;

        // Check positions of 'L'
        int t = 0;
        for (int i = 0; i < start.length(); ++i) {
            if (start[i] == 'L') {
                while (end[t] != 'L') t++; // find next L in end
                if (i < t) return false;   // L can only move to the left
                t++;
            }
        }

        // Check positions of 'R'
        t = 0;
        for (int i = 0; i < start.length(); ++i) {
            if (start[i] == 'R') {
                while (end[t] != 'R') t++; // find next R in end
                if (i > t) return false;   // R can only move to the right
                t++;
            }
        }

        return true;
    }
};
