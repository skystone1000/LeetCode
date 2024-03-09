// #0139. Word Break
// https://leetcode.com/problems/word-break/description/
// Company Tag - Apple,Amazon,Meta,Google,Microsoft,Walmart Labs, MongoDB

#include<bits/stdc++.h>
using namespace std;


// Approach 5: A Different DP
// Time complexity: O((n^3)+m⋅k), Space complexity: O(n+m⋅k)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


// Approach 4: Trie Optimization
// Time complexity: O((n^2)+m⋅k), Space complexity: O(n+m⋅k)
struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }

            curr->isWord = true;
        }

        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode* curr = root;
                for (int j = i; j < s.length(); j++) {
                    char c = s[j];
                    if (curr->children.find(c) == curr->children.end()) {
                        // No words exist
                        break;
                    }

                    curr = curr->children[c];
                    if (curr->isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
};


// Approach 3: Bottom-Up Dynamic Programming
// Time complexity: O(n⋅m⋅k), Space complexity: O(n)
// Solution from Editorial
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            for (string word : wordDict) {
                // Handle out of bounds case
                if (i < word.length() - 1) {
                    continue;
                }

                if (i == word.length() - 1 || dp[i - word.length()]) {
                    if (s.substr(i - word.length() + 1, word.length()) ==
                        word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
};


// Solution from Card
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, false);
        
        for (int i = 0; i < n; ++i) {
            for (const string& word : wordDict) {
                int len = word.length();
                
                // Ensure index is valid and previous dp state is true or it's the start of the string
                if (i >= len - 1 && (i == len - 1 || dp[i - len])) {
                    if (s.substr(i - len + 1, len) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n - 1];
    }
};



// Approach 2: Top-Down Dynamic Programming
// Time complexity: O(n⋅m⋅k), Space complexity: O(n)
// Editorial Approach
class Solution {
public:
    vector<int> memo;
    vector<string> wordDict;
    string s;

    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return dp(s.length() - 1);
    }

    bool dp(int i) {
        if (i < 0) return true;

        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        for (string word : wordDict) {
            int currSize = word.length();
            // Handle out of bounds case
            if (i - currSize + 1 < 0) {
                continue;
            }

            if (s.substr(i - currSize + 1, currSize) == word &&
                dp(i - currSize)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }
};

// Card Approach
class Solution {
public:
    string s;
    vector<string> wordDict;
    vector<int> memo;

    bool dp(int i) {
        if (i < 0) return true;

        if (memo[i] == -1) {
            for (const string& word : wordDict) {
                int len = word.length();
                if (i >= len - 1) {
                    // Recurrence relation
                    if (dp(i - len) && s.substr(i - len + 1, len) == word) {
                        memo[i] = 1;
                        break;
                    }
                }
            }
        }

        if (memo[i] == -1) {
            memo[i] = 0;
        }

        return memo[i] == 1;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->wordDict = wordDict;
        this->memo = vector<int>(s.length(), -1);
        return dp(s.length() - 1);
    }
};



// Approach 1: Breadth-First Search
// Time complexity: O((n^3)+m⋅k), Space complexity: O(n+m⋅k)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> queue;
        vector<bool> seen(s.length(), false);
        queue.push(0);

        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();

            if (start == s.length()) {
                return true;
            }

            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end()) {
                    queue.push(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
};