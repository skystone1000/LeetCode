// Company Amazon
// 19 #0973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        // Multimap is sorted in ASC order by key
        multimap<int,int> mymap;
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            mymap.insert({ x*x + y*y , i});
        }
        
        vector<vector<int>> ans;
        
        int count = 0;
        for(auto it = mymap.begin(); count<K ; it++,count++ ){
            ans.push_back(points[it->second]);
        }
        
        return ans;
    }
};

/*
// Time - Nlog(N)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<pair<int, pair<int,int>>> v;
        
        // FInd all distances
        int dist;
        for(auto point:points){
            dist = point[0] * point[0] + point[1] * point[1];
            v.push_back({dist, {point[0], point[1]}});
        }
        
        sort(v.begin(),v.end());
        
        vector<vector<int>> ans(K);
        for(int i=0;i<K;i++){
            ans[i].push_back(v[i].second.first);
            ans[i].push_back(v[i].second.second);
        }
        
        return ans;
    }
};
*/