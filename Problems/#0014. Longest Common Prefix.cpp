// Company Amazon
// 35 #0014. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string ans;
        
        for(int i=0;i<strs[0].size();i++){
            char check = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i>strs[j].size() || check != strs[j][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        
        string ans = "";
        int count = 0;
        for(char ch:strs[0]){
            for(string curr:strs){
                if(curr[count] != ch){
                    return ans;
                }
            }
            ans += ch;
            count++;
        }
        
        return ans;
    }
};