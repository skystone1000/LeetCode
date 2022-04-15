// #0947. Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - DFS
// Runtime: 68 ms, faster than 75.73% of C++ online submissions for Most Stones Removed with Same Row or Column.
// Memory Usage: 23.4 MB, less than 18.34% of C++ online submissions for Most Stones Removed with Same Row or Column.
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows, cols;
        unordered_set<int> v_rows;
        
        auto res = 0;
        for(auto s:stones){
            rows[s[0]].push_back(s[1]);
            cols[s[1]].push_back(s[0]);
        }
        
        for(auto r:rows){
            // The result is the total number of stones minus the number of groups
            // So total stones in each group and -1 for that group
            res += max( 0, dfs(rows,cols,v_rows, r.first)-1 );
        }
        
        return res;
    }
    
    int dfs(unordered_map<int, vector<int>> &rows, 
            unordered_map<int, vector<int>> &cols, 
            unordered_set<int> &v_rows, 
            int row){
        auto res = 0;
        if(v_rows.insert(row).second){
            res += rows[row].size();
            for(auto c:rows[row])
                for(auto r:cols[c])
                    res += dfs(rows, cols, v_rows, r);
        }
        return res;
    }
};