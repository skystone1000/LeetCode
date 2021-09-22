// Company Amazon
// AIE 9.8 #0044. Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        
        // Method 1 DP
        /*string str = s;
        string pattern = p;
        
        // Replace multiple * with one *
        // Ex a**b***c to a*b*c
        int writeIndex = 0;
        bool isFirst = true;
        for(int i=0;i<pattern.size();i++){
            if(pattern[i] == '*'){
                if(isFirst){
                    pattern[writeIndex++] = pattern[i];
                    isFirst = false;
                }
            } else {
                pattern[writeIndex++] = pattern[i];
                isFirst = true;
            }
        }
                
        vector<vector<bool>> T;
        for(int i=0;i<str.size()+1;i++){
            vector<bool> temp(writeIndex+1, false);
            T.push_back(temp);
        }
        
        if(writeIndex > 0 && pattern[0] == '*'){
            T[0][1] = true;
        }
        T[0][0] = true;
        
        for(int i=1;i<T.size();i++){
            for(int j = 1; j<T[0].size();j++){
                if(pattern[j-1] == '?' || str[i-1] == pattern[j-1]) {
                    T[i][j] = T[i-1][j-1];
                } else if(pattern[j-1] == '*'){
                    T[i][j] = T[i-1][j] || T[i][j-1];
                }
            }
        }
        
        return T[str.size()][writeIndex];
        */
        
        // Same solution but faster and smaller
        int n = s.length(), m = p.length();
        bool dp[n + 5][m + 5];
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;
        
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};