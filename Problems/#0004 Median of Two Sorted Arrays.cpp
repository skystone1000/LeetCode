// #0004. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;

// Method 2 - Optimal Solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

/*
// Method 1 - Obvious/Brute force
// Time - O(n+m) - n,m sizes of two vectors
// Space - O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merging 2 Vectors
        vector<int> merged;
        int n1=0, n2=0;
        while(n1<nums1.size() && n2<nums2.size()){
            if(nums1[n1] < nums2[n2]){
                merged.push_back(nums1[n1]);
                n1++;
            } else {
                merged.push_back(nums2[n2]);
                n2++;
            }
        }
        while(n1<nums1.size()){
            merged.push_back(nums1[n1]);
            n1++;
        }
        while(n2<nums2.size()){
            merged.push_back(nums2[n2]);
            n2++;
        }
        
        // Finding median
        if(merged.size() % 2 == 1){
            // cout<<"odd "<<merged.size()<<endl;
            double med = merged[merged.size()/2];
            return med;
        }
        double med = ( merged[(merged.size()/2)-1] + merged[(merged.size()/2)] ) / 2.0;
        return med;
    }
};
*/