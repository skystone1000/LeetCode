// #0004. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;

// Approach 3: A Better Binary Search
// Time complexity: O(log(min(m,n))), Space complexity: O(1) 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
};



// Approach 2: Binary Search, Recursive
// Time complexity: O(log(m⋅n)), Space complexity: O(logm+logn)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int na = int(A.size()), nb = int(B.size());
        int n = na + nb;
        if (n % 2) {
            return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return 1.0 *
                   (solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1) +
                    solve(A, B, n / 2, 0, na - 1, 0, nb - 1)) /
                   2;
        }
    }
    int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd,
              int bStart, int bEnd) {
        // If the segment of on array is empty, it means we have passed all
        // its element, just return the corresponding element in the other
        // array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
        // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
        return -1;
    }
};



// Approach 1: Merge Sort
// Time complexity: O(m+n), Space complexity: O(1)
/*
    Intuition
    Let's start with the straightforward approach. If we put the elements of two arrays 
    in one array A and arrange them in order. Assume the merged arrays has a length of n, 
    then the median is:
    - A[n / 2], if n is odd.
    - The average of A[n / 2] and A[n / 2 + 1], if n is even.
    However, we do not really need to merge and sort these arrays. Note that both arrays 
    are already sorted, so the smallest element is either the first element of nums1 or 
    the first element of nums2. Therefore, we can set two pointers p1 and p2 at the start
    of each array, then we can get the smallest element from the nums1 and nums2 by 
    comparing the values nums1[p1] and nums2[p2].
*/
class Solution {
public:
    int p1 = 0, p2 = 0;

    // Get the smaller value between nums1[p1] and nums2[p2] and move the
    // pointer forward.

    int getMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());

        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }

        return -1;
    }
};




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
