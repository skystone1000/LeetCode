// 2207. Maximize Number of Subsequences in a String
// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Brute Force
    int countBrute(string a, string b, int m, int n){

        // If both first and second string is empty,
        // or if second string is empty, return 1
        if ((m == 0 && n == 0) || n == 0)
            return 1;

        // If only first string is empty and second
        // string is not empty, return 0
        if (m == 0)
            return 0;

        // If last characters are same
        // Recur for remaining strings by
        // 1. considering last characters of both strings
        // 2. ignoring last character of first string
        if (a[m - 1] == b[n - 1])
            return countBrute(a, b, m - 1, n - 1) +
                   countBrute(a, b, m - 1, n);
        else
            // If last characters are different, ignore
            // last char of first string and recur for
            // remaining string
            return countBrute(a, b, m - 1, n);
    }
    
    // Top Down DP
    int countTopDown(string a, string b, int m, int n,
          vector<vector<int> >& dp)
    {
        // If both first and second string is empty,
        // or if second string is empty, return 1
        if ((m == 0 && n == 0) || n == 0)
            return 1;

        // If only first string is empty and second
        // string is not empty, return 0
        if (m == 0)
            return 0;

        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        // If last characters are same
        // Recur for remaining strings by
        // 1. considering last characters of both strings
        // 2. ignoring last character of first string
        if (a[m - 1] == b[n - 1])
            return dp[m][n] = countTopDown(a, b, m - 1, n - 1, dp)
                              + countTopDown(a, b, m - 1, n, dp);
        else
            // If last characters are different, ignore
            // last char of first string and recur for
            // remaining string
            return dp[m][n] = countTopDown(a, b, m - 1, n, dp);
    }
    
    // Bottom Up Approach
    long long countBottomUp(string a, string b)
    {
        long long m = a.length();
        long long n = b.length();

        // Create a table to store results of sub-problems
        long long lookup[m+1][n+1];
        
        for (long long i = 0; i <= m; ++i)
            for (long long j = 0; j <= n; ++j)
                lookup[i][j] = 0;
        

        // If first string is empty
        for (long long i = 0; i <= n; ++i)
            lookup[0][i] = 0;

        // If second string is empty
        for (long long i = 0; i <= m; ++i)
            lookup[i][0] = 1;

        // Fill lookup[][] in bottom up manner
        for (long long i = 1; i <= m; i++){
            for (long long j = 1; j <= n; j++){
                // If last characters are same, we have two
                // options -
                // 1. consider last characters of both strings
                //    in solution
                // 2. ignore last character of first string
                if (a[i - 1] == b[j - 1])
                    lookup[i][j] = lookup[i - 1][j - 1] + lookup[i - 1][j];

                else
                    // If last character are different, ignore
                    // last character of first string
                    lookup[i][j] = lookup[i - 1][j];
            }
        }

        return lookup[m][n];
    }
    
    long long maximumSubsequenceCount(string text, string pattern) {
        string updatedText = "";
        pair<long long,long long> countPair = {0,0};
        for(long long i=0;i<text.size();i++){
            if(text[i] == pattern[0]){
                updatedText += text[i];
                countPair.first++;
            }
            else if(text[i] == pattern[1]){
                updatedText += text[i];
                countPair.second++;   
            }
        }
        string addedChar = "";
        if(countPair.first < countPair.second){
            addedChar = pattern[0] + updatedText;
        }else{
            addedChar = updatedText + pattern[1];            
        }
        // cout<<addedChar<<endl;

        // Method 1 - Brute Force
        // return countBrute(addedChar, pattern, addedChar.size(), pattern.size());
        
        // Methos 2 - Top Down DP
        // vector<vector<int> > dp(addedChar.size() + 1, vector<int>(pattern.size() + 1, -1));
        // return countTopDown(addedChar, pattern, addedChar.size(), pattern.size(), dp);
        
        // Method 3 - Bottom Up DP
        return countBottomUp(addedChar, pattern);
        
    }
    
    
};