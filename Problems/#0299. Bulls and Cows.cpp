// #0299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2 : One pass
// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {
        int h[10] = {0};  // Frequency map for digits 0-9
        int bulls = 0, cows = 0;
        int n = secret.size();

        for (int i = 0; i < n; ++i) {
            char s = secret[i];
            char g = guess[i];
            if (s == g) {
                bulls++;  // Same digit and same position
            } else {
                // If secret's digit s was already guessed too many times (-ve from update freq below), it's a cow
                if (h[s - '0'] < 0) cows++;

                // If guess's digit g was seen in secret earlier, it's a cow
                if (h[g - '0'] > 0) cows++;

                // Update frequencies
                h[s - '0']++;
                h[g - '0']--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

// Approach 1: HashMap: Two Passes
// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> h;
        // Count frequency of each character in secret
        for (char s : secret) {
            h[s]++;
        }
        int bulls = 0, cows = 0;
        int n = guess.length();
        for (int idx = 0; idx < n; ++idx) {
            char ch = guess[idx];
            // Check only if character exists in secret
            if (h.count(ch)) {
                if (ch == secret[idx]) {
                    // Exact match => bull
                    bulls++;
                    // If we previously overcounted this character as cow, adjust
                    if (h[ch] <= 0)
                        cows--;
                } else {
                    // Partial match => cow only if available in frequency map
                    if (h[ch] > 0)
                        cows++;
                }
                // Mark the character as used
                h[ch]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};


// Approach 1: HashMap: Two Passes (Way 2)
// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> present;
        int bulls = 0, cows = 0;
        int n = secret.size();

        // First pass: Count bulls only
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                // Only count non-bull characters
                present[secret[i]]++;
            }
        }

        // Second pass: Count cows only for non-bulls
        for (int i = 0; i < n; ++i) {
            if (secret[i] != guess[i]) {
                if (present[guess[i]] > 0) {
                    cows++;
                    present[guess[i]]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
    
    