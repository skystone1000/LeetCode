// April Challenge 2021 - Day 23 - #0696. Count Binary Substrings
// #0696. Count Binary Substrings
// https://leetcode.com/problems/count-binary-substrings/

// Time - O(N), Space - O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGC = 0; // Previous Group Count
        int currGC = 1; // Current Group Count
        int ans = 0;    // Binary valid Substrings Count
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] != s[i]) {
                ans += min(prevGC, currGC);
                prevGC = currGC;
                currGC = 1;
            } else {
                currGC++;
            }
        }

        ans += min(prevGC, currGC);
        return ans;
    }
};


// Time - O(N) (Two Pass), Space - O(N)
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups(s.size());
        int idx = 0;
        groups[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] != s[i]) {
                idx++;
                groups[idx] = 1;
            } else {
                groups[idx]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= idx; i++) {
            ans += min(groups[i-1], groups[i]);
        }
        return ans;
    }
};
