// LeetCode arrays 15
// #1051 Height Checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedStd;
        //sortedStd.reserve(heights.size());
        
        for(int i=0;i<heights.size();i++){
            sortedStd.push_back(heights[i]);
        }
        sort(sortedStd.begin(),sortedStd.end());
        
        int changedCount = 0;
        for(int i=0;i<sortedStd.size();i++){
            cout<<sortedStd[i]<<"="<<heights[i];
            if(sortedStd[i] != heights[i]){
                changedCount++;
            }
        }
        
        return changedCount;
    }
};