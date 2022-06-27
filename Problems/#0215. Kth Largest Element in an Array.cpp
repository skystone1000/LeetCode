// #0215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<bits/stdc++.h>
using namespace std;

// Method 2 - Max heap
// Time - 8 ms AVG O(N), Space - 10.5 MB O(N) can be reduced to O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max Heap
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            if(i==k-1)
                return q.top();
            else
                q.pop();
        }
        return -1;
    }
};

// Method 2 - Sorting
// 	Time - 18 ms, Space - 10.1 MB
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
*/