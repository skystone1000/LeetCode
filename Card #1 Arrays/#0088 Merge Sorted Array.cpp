// LeetCode arrays 5
// #0088 Merge Sorted Array   

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        ans.reserve(m+n);
        std::merge(nums1.begin(), nums1.begin()+m, nums2.begin(), nums2.begin()+n, ans.begin() );
        
        for(int i=0;i<m+n;i++){
            nums1[i] = ans[i];
        }
    }
};