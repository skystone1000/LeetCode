// #0242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Frequency Counter
// Time complexity: O(n), Space complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // Step 2: Create a counter array for 26 lowercase letters
        int counter[26] = {0};
        // Step 3: Increment for characters in 's', decrement for 't'
        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        // Step 4: Check if all counts are zero
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0) {
                return false;
            }
        }
        // Step 5: All counts matched
        return true;
    }
};



// Approach 1: Sorting
// Time complexity: O(nlogn), Space complexity: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
