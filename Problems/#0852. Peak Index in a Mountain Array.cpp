// #0852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Binary Search
// Time complexity: O(logn), Space complexity: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};


// Approach 1: Linear Scan
// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            i++;
        }
        return i;
    }
};
