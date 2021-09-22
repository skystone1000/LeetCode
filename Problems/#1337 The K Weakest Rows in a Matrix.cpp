// Search array 14
// #1337 The K Weakest Rows in a Matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> freq;
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    count++;
                }else{
                    break;
                }
            }
            freq.push_back({count,i});
        }
        
        sort(freq.begin(),freq.end());
        
        vector<int> ans;
        int i=0;
        for(pair el:freq){
            if(i>=k){
                break;
            }
            ans.push_back(el.second);
            i++;
        }
        
        return ans;
    }
};