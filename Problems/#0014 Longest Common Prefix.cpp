// LeetCode Arrays & Strings - 9
// #0014 Longest Common Prefix

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