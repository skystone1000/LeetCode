// LeetCode arrays 5
// #0088 Merge Sorted Array   

#include<bits/stdc++.h>
using namespace std;

// Method 1 - Two Pointer approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int n1=0, n2=0;
        // Adding smaller elements in ans till one vector is empty
        while(n1<m && n2<n){
            if(nums1[n1]<nums2[n2]){
                ans.push_back(nums1[n1]);
                n1++;
            }else{
                ans.push_back(nums2[n2]);
                n2++;
            }
        }
        
        // Adding Remaining elements of larger vector
        if(n1==m){
            for(int i=n2;i<n;i++){
                ans.push_back(nums2[i]);
            }
        }else{
            for(int i=n1;i<m;i++){
                ans.push_back(nums1[i]);
            }
        }
        
        // Updating First Vector
        for(int i=0;i<m+n;i++){
            nums1[i] = ans[i];
        }
    }
};


// Method 2 - Inbuilt Function
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