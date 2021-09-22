// May Challenge 2021 - Day 18
// #0609. Find Duplicate File in System
// https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector< vector<string> > ans;
        unordered_map<string, vector<string> > m;
        
        for(string path: paths) {
            string pt;
            int i;
            for(i = 0; i <  path.size() && path[i] != ' '; i++) 
                pt += path[i];
            pt += '/'; // common part for every file
            i++; // skip the space
            
            while(i < path.size()) {
                string file, data;
                
                while(i < path.size() && path[i] != '(') 
                    file += path[i++];
                
                while(i < path.size() && path[i] != ' ') 
                    data += path[i++];
                
                m[data].push_back(pt + file);
                ++i;
            }
        }
        
        for(auto &x: m) {
            if(x.second.size() > 1) 
                ans.push_back(x.second);
        }
        return ans;
    }
};