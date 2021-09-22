// Company Amazon
// 23 #0049. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anag;
        for(string current : strs){
            string sorted = current;
            sort(sorted.begin(),sorted.end());
            if(anag.count(sorted) > 0){
                anag[sorted].push_back(current);
            } else {
                vector<string> temp;
                temp.push_back(current);
                anag.insert({sorted, temp});
            }
        }
        
        vector<vector<string>> ans;
        for(auto ele : anag){
            ans.push_back(ele.second);
        }
        return ans;
    }
};