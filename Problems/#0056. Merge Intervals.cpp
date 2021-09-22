// Company Amazon
// 55 #0056. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        
        stack<pair<int,int>> st;
        sort(intervals.begin(), intervals.end());
        
        for(auto ele:intervals){
            if(st.empty()){
                st.push({ele[0],ele[1]});
                continue;
            }
            pair<int,int> topEle = st.top();
            // cout<<topEle.first<<" "<<topEle.second<<endl;
            if(topEle.second < ele[0]){
                st.push({ele[0],ele[1]});
            } else if(topEle.second <= ele[1]){
                st.pop();
                topEle.second = ele[1];
                st.push(topEle);
            }
        }
        
        vector<vector<int>> ans;
        while(st.empty() == false){
            // Append top in the ans
            ans.push_back({st.top().first, st.top().second});
            st.pop();
        }
        
        return ans;
    }
};