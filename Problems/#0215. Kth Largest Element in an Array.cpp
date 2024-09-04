// #0215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 4: Counting Sort
// Time complexity: O(n+m), Space complexity: O(m)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        vector<int> count(maxValue - minValue + 1);
        for (int num: nums) {
            count[num - minValue]++;
        }
        int remain = k;
        for (int num = count.size() - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0) {
                return num + minValue;
            }
        }
        return -1;
    }
};

// Approach 3: Quickselect
// Time complexity: O(n) on average, O(n2) in the worst case
// Space complexity: O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        for (int num: nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        if (k <= left.size()) {
            return quickSelect(left, k);
        }
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }
        return pivot;
    }
};

// Approach 2: Min-Heap
// Time complexity: O(n⋅logk), Space complexity: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max Heap but pusing with multiplying by -1 so becomes reverse
        priority_queue<int> heap; 
        for (int num: nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        return -heap.top();
    }
};

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

// Approach 1: Sort
// Time complexity: O(n⋅logn), Space Complexity: O(logn) or O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};