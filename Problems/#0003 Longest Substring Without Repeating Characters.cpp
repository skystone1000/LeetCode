// #0003. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

// Approach 3: Sliding Window Optimized
// Time complexity : O(n), Space complexity : O(min(m,n))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> charToNextIndex;

        for (int right = 0, left = 0; right < n; right++) {
            if (charToNextIndex[s[right]] > 0) {
                left = max(charToNextIndex[s[right]], left);
            }
            res = max(res, right - left + 1);
            charToNextIndex[s[right]] = right + 1;
        }
        return res;
    }
};


// Approach 2: Sliding Window
// Time complexity : O(2.n)=O(n), Space complexity : O(min(m,n))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char rightChar = s[right];
            chars[rightChar]++;

            while (chars[rightChar] > 1) {
                char leftChar = s[left];
                chars[leftChar]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};


// Approach 2: Set - modified Sliding Window
// Time Complexity: O(n), Space Complexity: O(min of a,b)
// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/376363/CPP-Solution-for-beginners-or-O(n)-time-or-Longest-Substring-without-repeating-characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left=0, right=0, n=s.size(), ans = 0;
        
        while(left<n && right<n){
            // If current character is not found in set
            if(set.find(s[right]) == set.end()){
                set.insert(s[right]);
                right++;
                ans = max(ans, right-left);
            }  else { 
                // If character does exist in the set, ie. it is a repeated character, 
				// we update the left side counter i, and continue with the checking for substring.
                set.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};


// Approach 1: Brute Force (TLE)
// Time complexity: O((N^3)LogN))
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


// Time complexity : O(n^3), Space complexity : O(min(n,m))
// We need O(k) space for checking a substring has no duplicate characters, where k is the size of the Set. The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        unordered_set<char> chars;

        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (chars.count(c)) {
                return false;
            }
            chars.insert(c);
        }

        return true;
    }
};